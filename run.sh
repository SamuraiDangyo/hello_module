# 2025 (C) Toni Helminen
# Run a simple Linux module and remove it

# Compile the module
make

# Load the module into the kernel
sudo insmod hello.ko

# Check the kernel log to see the output
dmesg | tail

# Remove the module from the kernel
sudo rmmod hello

# Check the kernel log again to see the exit message
dmesg | tail

# Clean up
make clean
