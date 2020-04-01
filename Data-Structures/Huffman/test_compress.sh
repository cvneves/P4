i=0
for file_name in instance/*.txt;
do
    ./huffman -c "$file_name" "$file_name.hx"
done
