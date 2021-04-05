#!/bin/sh
# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2018 Intel Corporation. All rights reserved.

set -e
exec git show --format=email HEAD | ./scripts/checkpatch.pl --no-tree --strict --codespell
