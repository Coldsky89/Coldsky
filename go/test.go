package main

import "fmt"

func Reverse(sPtr *string) string {
	sLen := len(*sPtr)
	for i := 0;i < sLen/2;i++ {
		temp := *(sPtr+i)
		*(sPtr+i) = *(sPtr+sLen-1-i)
		*(sPtr+sLen-1-i) = temp
	}
	return *sPtr
}

func BigNumAdd(s string, t string) string {
	if len(s) < len(t) {
		temp := s
		s = t
		t = temp
	}

	s = Reverse(&s)
	t = Reverse(&t)

	carry := 0
	for i := 0; i < len(s);i++ {
		bitSum := 0
		bitSum += int(s[i])
		if i < len(t) {
			bitSum += int(t[i])
		}
		bitSum += carry
		if bitSum > 10 {
			bitSum = bitSum % 10
			carry = 1
		} else {
			carry = 0
		}
		s[i] = int8(bitSum)
	}
	if carry > 1 {
		s = s + "1"
	}
	return Reverse(&s)
}

func main() {
	s := ""
	t := ""

	res := BigNumAdd(s, t)

	fmt.Println(res)
}
