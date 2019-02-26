for (( i=1; i<=$1; i++ ))
    do
        IDADE=$(((RANDOM %100)+1))
        echo "./program -a Pessoa${i} $IDADE"

        ./program -a Pessoa${1} $IDADE
done

