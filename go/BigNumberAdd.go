package main

import "fmt"

/*
func reverse(sPtr *string) string {
    temp := *sPtr
    sLen := len(temp)

    for i := 0; i < sLen/2; i++ {
        tc := temp[i]
        temp[i] = temp[sLen-1-i]
        temp[sLen-1-i] = tc
    }
    
    return tc
}
*/

func reverse(sPtr *string) string {
    temp := *sPtr
    sLen := len(temp)
    var res string

    for i := 0; i < sLen; i++ {
        res += fmt.Sprintf("%c", temp[sLen - 1 - i])
    }

    return res
}


func swap(sPtr *string, tPtr *string) {
    temp := *sPtr
    *sPtr = *tPtr
    *tPtr = temp
}

func BigNumberAdd(s string, t string) string {
    if len(s) < len(t) {
        swap(&s, &t)
    }

    s = reverse(&s)
    t = reverse(&t)
   
    var res string

    carry := 0
    for i := 0; i < len(s); i++ {
        bitSum := 0
        bitSum += int(int(s[i]) - int('0'))
        if i < len(t) {
            bitSum += int(int(t[i]) - int('0'))
        }
        
        bitSum += carry
        carry = bitSum / 10
        
        res += fmt.Sprintf("%c", bitSum%10 + int('0'))
    }

    if carry > 0{
        res += fmt.Sprintf("%c", carry+int('0'))
    }
    
    res = reverse(&res)

    return res
}
        

func main() {
    var s string
    var t string
    var res string
    for i := 0; i < 5; i++ {
        fmt.Scanf("%s", &s)
        fmt.Scanf("%s", &t)

        res = BigNumberAdd(s, t)
        fmt.Println(res)
    }
}
