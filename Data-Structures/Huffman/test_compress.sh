i=0
for file_name in random_instances/*;
do
    ./huffman -c "$file_name" "$file_name.hx"
done
