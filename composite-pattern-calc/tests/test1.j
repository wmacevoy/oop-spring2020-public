.class public tests/test1
.super java/lang/Object

; default constructor
.method public <init>()V
   aload_0 ; push this
   invokespecial java/lang/Object/<init>()V ; call super
   return
.end method

.method public static main([Ljava/lang/String;)V
begin:
   .limit stack 100
   .limit locals 100
   .var 0 is ans F from begin to end
   .var 1 is a F from begin to end
   .var 2 is b F from begin to end
   .var 3 is c F from begin to end
   .var 4 is d F from begin to end
   .var 5 is e F from begin to end
   .var 6 is f F from begin to end
   .var 7 is g F from begin to end
   .var 8 is h F from begin to end
   .var 9 is i F from begin to end
   .var 10 is j F from begin to end
   .var 11 is k F from begin to end
   .var 12 is l F from begin to end
   .var 13 is m F from begin to end
   .var 14 is n F from begin to end
   .var 15 is o F from begin to end
   .var 16 is p F from begin to end
   .var 17 is q F from begin to end
   .var 18 is r F from begin to end
   .var 19 is s F from begin to end
   .var 20 is t F from begin to end
   .var 21 is u F from begin to end
   .var 22 is v F from begin to end
   .var 23 is w F from begin to end
   .var 24 is x F from begin to end
   .var 25 is y F from begin to end
   .var 26 is z F from begin to end
   ldc 1.0
   ldc 97.0
   fdiv
   fstore 1
   ldc 1.0
   ldc 98.0
   fdiv
   fstore 2
   ldc 1.0
   ldc 99.0
   fdiv
   fstore 3
   ldc 1.0
   ldc 100.0
   fdiv
   fstore 4
   ldc 1.0
   ldc 101.0
   fdiv
   fstore 5
   ldc 1.0
   ldc 102.0
   fdiv
   fstore 6
   ldc 1.0
   ldc 103.0
   fdiv
   fstore 7
   ldc 1.0
   ldc 104.0
   fdiv
   fstore 8
   ldc 1.0
   ldc 105.0
   fdiv
   fstore 9
   ldc 1.0
   ldc 106.0
   fdiv
   fstore 10
   ldc 1.0
   ldc 107.0
   fdiv
   fstore 11
   ldc 1.0
   ldc 108.0
   fdiv
   fstore 12
   ldc 1.0
   ldc 109.0
   fdiv
   fstore 13
   ldc 1.0
   ldc 110.0
   fdiv
   fstore 14
   ldc 1.0
   ldc 111.0
   fdiv
   fstore 15
   ldc 1.0
   ldc 112.0
   fdiv
   fstore 16
   ldc 1.0
   ldc 113.0
   fdiv
   fstore 17
   ldc 1.0
   ldc 114.0
   fdiv
   fstore 18
   ldc 1.0
   ldc 115.0
   fdiv
   fstore 19
   ldc 1.0
   ldc 116.0
   fdiv
   fstore 20
   ldc 1.0
   ldc 117.0
   fdiv
   fstore 21
   ldc 1.0
   ldc 118.0
   fdiv
   fstore 22
   ldc 1.0
   ldc 119.0
   fdiv
   fstore 23
   ldc 1.0
   ldc 120.0
   fdiv
   fstore 24
   ldc 1.0
   ldc 121.0
   fdiv
   fstore 25
   ldc 1.0
   ldc 122.0
   fdiv
   fstore 26
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
fload 18
ldc 4.000000000000000
fadd
fload 5
ldc 490.000000000000000
fmul
fadd
fload 1
ldc 3.000000000000000
fload 3
fmul
fadd
fmul
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
fload 19
fload 25
fmul
fload 1
fload 26
fmul
fmul
fload 11
ldc 5.000000000000000
fadd
ldc 337.000000000000000
ldc 501.000000000000000
fadd
fmul
fmul
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
fload 5
ldc 1.000000000000000
fmul
fload 21
ldc 8.000000000000000
fmul
fmul
ldc 8.000000000000000
fload 23
fadd
ldc 2.000000000000000
ldc 1.000000000000000
fadd
fadd
fmul
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
fload 11
ldc 6.000000000000000
fadd
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
ldc 5.000000000000000
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; push java.lang.System.out (type PrintStream)
   getstatic java/lang/System/out Ljava/io/PrintStream;
   
fload 8
ldc 6.000000000000000
fadd
fload 3
ldc 0.000000000000000
fadd
fmul
ldc 8.000000000000000
ldc 0.000000000000000
fadd
fload 6
fload 21
fmul
fadd
fadd
   
   ; invoke println
   invokevirtual java/io/PrintStream/println(F)V
   
   ; terminate main
   return
end:
.end method
