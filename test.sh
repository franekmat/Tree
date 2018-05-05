#!/bin/bash
diag=0;
wrong=0;
if [ "$1" == "-v" ]
then
    prog=$2
    dir=$3
    diag=1
else
    prog=$1
    dir=$2
fi

for i in $dir/*.in
do
    if [ "$diag" == 0 ]
    then
        ./"$prog" < "$i" > test.out
    else
        ./"$prog" -v < "$i" > test.out 2> test.err
    fi

    name=${i:0:${#i}-3}
    number=${name:10:${#name}0}

    DIFF=$(diff test.out "$name".out)
    if [ "$DIFF" != "" ]
    then
        echo "Test $number: wrong answer"
        wrong=1
    fi

    if [ "$diag" == 1 ]
    then
        DIFF=$(diff test.err "$name".err)
        if [ "$DIFF" != "" ]
        then
            echo "(Diagnostyczny $number: wrong answer)"
            wrong=1
        fi
    fi
done

if [ "$wrong" == 0 ]
then
    echo "Everything is OK"
fi
