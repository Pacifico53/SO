for i in `seq 1000000` ; do
    echo $i
    ./program -a Person$RANDOM $RANDOM
done
