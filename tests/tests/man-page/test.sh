#!/bin/bash
#
# Run legacy table regression testing
#

if [ -z "$TESTBASE" ] ; then
	echo TESTBASE needs to be passed via the env
	exit 1
fi

. $TESTBASE/test-functions

DETOX=$1
INLINE=$(dirname $DETOX)/inline-detox

# ----------------------------------------------------------

INPUT=$(printf "\t \$ &")

# ----------------------------------------------------------

WHICH=C.UTF-8

FOUND=$(locale -a | grep -c '^C[.]')

if [ "$FOUND" -gt 0 ] ; then
	OUTPUT="tab_dollar_and_"
	LANG=$WHICH
	LC_ALL=$WHICH
	LC_CTYPE=$WHICH

	CHECK=$(echo "$INPUT" | $INLINE -f detoxrc.manpage)
	if [ "$CHECK" != "$OUTPUT" ] ; then
		echo "Man page is a lie. LANG=$WHICH"
		locale
		exit 1
	fi
else
	echo "skipping LANG=$WHICH ... not installed"
fi

# ----------------------------------------------------------

WHICH=de_DE.UTF-8

FOUND=$(locale -a | grep -c '^de_DE')

if [ "$FOUND" -gt 0 ] ; then
	OUTPUT="tab_dollar_and_"
	LANG=$WHICH
	LC_ALL=$WHICH
	LC_CTYPE=$WHICH

	CHECK=$(echo "$INPUT" | $INLINE -f detoxrc.manpage)
	if [ "$CHECK" != "$OUTPUT" ] ; then
		echo "Man page is a lie. LANG=$WHICH"
		locale
		exit 1
	fi
else
	echo "skipping LANG=$WHICH ... not installed"
fi

# ----------------------------------------------------------

WHICH=en_US.UTF-8

FOUND=$(locale -a | grep -c '^en_US')

if [ "$FOUND" -gt 0 ] ; then
	OUTPUT="tab_money_and_"
	LANG=$WHICH
	LC_ALL=$WHICH
	LC_CTYPE=$WHICH

	CHECK=$(echo "$INPUT" | $INLINE -f detoxrc.manpage)
	if [ "$CHECK" != "$OUTPUT" ] ; then
		echo "Man page is a lie. LANG=$WHICH"
		locale
		exit 1
	fi
else
	echo "skipping LANG=$WHICH ... not installed"
fi