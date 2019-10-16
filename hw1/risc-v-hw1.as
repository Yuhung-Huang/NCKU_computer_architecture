.data 

str1: .string " 1 + 2 = "
str2: .string " 1 + 2 + 3 = "
str3: .string " 1 + 2 + 3 + 4 = "
blank: .string "  ///  "
.text
addi s0, x0, 1
addi s1, x0, 2
addi s2, x0, 3
addi s3, x0, 4
add s5, s0, s1
la a1 str1
li a0 4
ecall
mv a1 s5
li a0 1
ecall
la a1 blank
li a0 4
ecall
add s5, s5, s2
la a1 str2
li a0 4
ecall
mv a1 s5
li a0 1
ecall
la a1 blank
li a0 4
ecall
add s5, s5, s3
la a1 str3
li a0 4
ecall 
mv a1 s5
li a0 1
ecall
la a1 blank
li a0 4
ecall