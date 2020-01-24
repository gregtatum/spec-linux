echo "Building and running my app"
# gcc -o linux-app src/main.c
make
./linux-app
echo "Exit code: $?"
