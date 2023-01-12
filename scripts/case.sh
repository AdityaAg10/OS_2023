#! /bin/bash

echo "Enter a value"

	read myval
	case "$myval" in
	0) echo "zero";;
	1) echo "one";;
	2) echo "two";;
	3) echo "three";;
	*) echo "Invalid Argument";;
	esac
