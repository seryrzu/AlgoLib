#!/usr/bin/env bash
set -e
set -x

find test -name 'tests_generator.py' | while read line; do
    python "$line"
done
