cd samples
# Create directories
mkdir -p dir{1..5}/subdir{1..3}

# Create random sized files in these directories
for d in dir*/subdir*; do
  for i in {1..5}; do
    dd if=/dev/urandom of="${d}/file${i}.txt" bs=1 count=$(( RANDOM + 1024 ))
  done
done

# Create empty files
touch dir{1..5}/emptyfile{1..3}.txt
