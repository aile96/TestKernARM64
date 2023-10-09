Compiling
=========

1. Assuming arm-none-eabi- is in your path:
2. Run "make" to build
4. Supported targets: QEMU's virt model

Usage
=====

Example: qemu-system-aarch64
		-nographic
		-M virt -cpu cortex-a53
		-kernel build-virt/image-virt.axf

