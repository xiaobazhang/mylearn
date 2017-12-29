#!/usr/bin/env bash

Path="/Users/suli/window/mnt/tool/"
source="package/app_module_dntg.td3guoPackage"
name="app_module_dntg.td3guoPackage"
file="app.module.dntg.controller.DntgController"

screte="AAAAB3NzaC1yc2EAAAABIwAAAQEArk8etQ7S/Uj2QOrzhw54df6LQttJLvRR5qsLLrVxOE5mBG2tl6Q+A4Pj044VinCSRCCwTmUJZRHBOpfN3S1Iuj8teYwANMzffjkE"

cp -rf $Path$source $Path"tmp"

cd $Path"des/"

cp -rf * $Path"tmp/"$name

cd "$Path""tmp/""$name"

zip -r "$Path""tmp/encry/""$name" *

rc4tool $Path"tmp/encry/"$name $Path"apk/"$name $screte