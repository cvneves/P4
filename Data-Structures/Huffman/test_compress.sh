i=0
for file_name in instance/*;
do
    echo "$file_name"
    ./huffman -c "$file_name" "$file_name.hx"
done
