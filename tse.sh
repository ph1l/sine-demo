#!/bin/sh

stty -icanon min 1
./tse ${*}

