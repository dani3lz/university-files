import time
from math import *

fib1_schimbari=fib2_schimbari=fib3_schimbari=0

def pause():
    programPause = input("\nPress the <ENTER> key to continue...\n")

def fib1(n):
	global fib1_schimbari
	if (n<2):
		return n
	else:
		fib1_schimbari+=1
		return fib1(n-1) + fib1(n-2)

def fib2(n):
	global fib2_schimbari
	i,j=0,1
	for k in range(n):
		i,j=j,i+j
		fib2_schimbari+=1
	return i

def fib3(n):
	global fib3_schimbari
	PHI = (1+sqrt(5))/2
	fn = 1
	t = 1
	n -=1
	while t < n: 
		fn = round(fn * PHI) 
		t+=1
		fib3_schimbari+=1
	return fn 

def main():
	n = input("Dati numarul n (n>0):\t")
	n = int(n)

	fib_counter1 = time.perf_counter()
	fib1_number = fib1(n)
	fib_counter2 = time.perf_counter()
	fib1_counter = fib_counter2 - fib_counter1

	fib_counter1 = time.perf_counter()
	fib2_number = fib2(n)
	fib_counter2 = time.perf_counter()
	fib2_counter = fib_counter2 - fib_counter1

	fib_counter1 = time.perf_counter()
	fib3_number = fib3(n)
	fib_counter2 = time.perf_counter()
	fib3_counter = fib_counter2 - fib_counter1

	print("\n[Recursiva] Numarul {} in sirul Fibonacci este {}".format(n,fib1_number))
	print("A fost calculat in:\n {:.8f} secunde\n {} etape".format(fib1_counter,fib1_schimbari))
	print("\n[Iterativa] Numarul {} in sirul Fibonacci este {}".format(n,fib2_number))
	print("A fost calculat in:\n {:.8f} secunde\n {} etape".format(fib2_counter,fib2_schimbari))
	print("\n[Golden] Numarul {} in sirul Fibonacci este {}".format(n,fib3_number))
	print("A fost calculat in:\n {:.8f} secunde\n {} etape".format(fib3_counter,fib3_schimbari))

	pause()

if __name__ == '__main__':
	main()