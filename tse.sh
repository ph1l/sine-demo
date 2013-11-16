#!/bin/sh

stty -icanon min 1
stty -echo
./tse ${*}
stty echo

