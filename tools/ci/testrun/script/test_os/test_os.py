#!/usr/bin/env python3
############################################################################
# tools/ci/testrun/script/test_os/test_os.py
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################
# encoding: utf-8
import os

import pytest

pytestmark = [pytest.mark.common, pytest.mark.qemu]
do_not_support = ["sabre-6quad", "rv-virt", "rv-virt64", "esp32c3-devkit", "bl602evb"]


def test_ostest(p):
    if p.board == "sim":
        os.mkdir("./test")
        ret = p.sendCommand("mount -t hostfs -o fs=./test /data")

    ret = p.sendCommand("ostest", "Exiting with status 0", timeout=300)
    assert ret == 0


def test_mm(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    ret = p.sendCommand("heap", "TEST COMPLETE", timeout=120)
    assert ret == 0


def test_cxxtest(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    ret = p.sendCommand("cxxtest", "Test std::map")
    assert ret == 0


def test_scanftest(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    ret = p.sendCommand("scanftest", "FAILED: 0")
    assert ret == 0


def test_getprime(p):
    if p.board in ["rv-virt", "rv-virt64"]:
        pytest.skip("unsupported at {}".format(p.board))
    ret = p.sendCommand("getprime", "getprime took")
    assert ret == 0


def test_stdio(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    ret = p.sendCommand("fopencookie_test", "fopencokie tests were succesfull.")
    assert ret == 0
    ret = p.sendCommand("fmemopen_test", "FAILED: 0")
    assert ret == 0
    ret = p.sendCommand("open_memstream_test", "FAILED: 0")
    assert ret == 0


@pytest.mark.run(order=-2)
def test_fs_test(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    fstest_dir = "{}/{}_fstest".format(p.fs, p.core)
    p.sendCommand("mkdir %s" % fstest_dir)
    ret = p.sendCommand("fstest -n 10 -m %s" % fstest_dir, "FAILED: 0", timeout=2000)
    p.sendCommand("ls %s" % fstest_dir)
    p.sendCommand("rmdir %s" % fstest_dir)

    if p.board == "sim":
        os.rmdir("./test")
    assert ret == 0


@pytest.mark.run(order=-1)
def test_psram_test(p):
    if p.board in do_not_support:
        pytest.skip("unsupported at {}".format(p.board))
    if p.sendCommand("ls /", "tmp/") == 0:
        ret = p.sendCommand("fstest -n 10 -m /tmp", "Final memory usage", timeout=500)
        p.sendCommand("ls /tmp")
        assert ret == 0
