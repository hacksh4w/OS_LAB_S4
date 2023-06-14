echo "Fibonacci series:"
read num
a=0
b=1
for ((i=0;i<$num;i++))
do
    echo $a
    temp=$a
    a=$b
    b=$((temp+b))
done
