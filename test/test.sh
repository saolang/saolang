echo<<ASM

echo 222
echo 333

ASM

((0)) && {
	echo 444
} || {
	echo 555
}
