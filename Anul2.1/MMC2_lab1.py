from math import *
from sympy import *
import sys
sys.setrecursionlimit(1000)

x, y = symbols('x y')

''' ##### Parametrii care pot fi schimbati #####'''
''' Functia este convexa '''
func = 2*x**2 + 3*x*y + 6*y**2 - 6*x - 2*y
''' Pasul '''
lambd = 1
'''Se aplcia p/u fractionarea pasului '''
omega = 1/2
''' Eroarea admisibila '''
eps = 10**(-6)
delt = 0.06
''' Coordonatele de unde se incepe rezolvarea '''
x0 = [2,6]
''' ################################ '''

def pause():
    programPause = input("\nPress the <ENTER> key to continue...\n")

def f(x,y):
	return func

def fcalc(x1,y1):
	ff = f(x,y)
	func = ff.subs([(x,x1),(y,y1)])
	return func

def gradientul(x1,y1):
	gx = diff(f(x,y),x)
	gy = diff(f(x,y),y)
	gradx = gx.subs([(x,x1),(y,y1)])
	grady = gy.subs([(x,x1),(y,y1)])
	gradient = [gradx,grady]
	return gradient

def magnitudinea(x1,y1):
	gradient = gradientul(x1,y1)
	mag = sqrt(pow(gradient[0],2) + pow(gradient[1],2))
	return mag

def pretendent(x1,y1,lambd):
	grad = gradientul(x1,y1)
	val2 = [grad[0]*lambd,grad[1]*lambd]
	first = x1 - grad[0]*lambd
	second = y1 - grad[1]*lambd
	'''(-) p/u minimizare ||| (+) p/u maximizare '''
	z = [first, second]
	return z

def rezolv(x1,y1,lambd,limit):
	limit+=1
	z = pretendent(x1,y1,lambd)
	f0 = fcalc(x1,y1)
	fz = fcalc(z[0],z[1])
	gradz = gradientul(z[0],z[1])
	magnit0 = magnitudinea(x1,y1)
	magnitz = magnitudinea(z[0],z[1])
	''' limit - nr de iteratii la care programul se stopeaza daca nu a ajuns la conditia de stopare '''
	if magnitz < eps or limit == 1000: 
		print("\n<Conditia de stopare a fost atinsa!> Nr:", str(limit))
		print("\nz = ", str(z))
		print("F(z) = ", str(fz))
		print("Gradientul = ", str(gradz))
		print("Magnitudinea = ", str(magnitz))
		pause()
	else:
		if fz-f0 <= -delt*lambd*pow(magnit0,2):
			x1 = z[0]
			y1 = z[1]
			print("\nSATISFACE Nr:", str(limit))
			print("z = ", str(z))
			print("F(z) = ", str(fz))
			print("Gradientul = ", str(gradz))
			print("Magnitudinea = ", str(magnitz))
			print("---------------------------------------------------------")
			rezolv(x1,y1,lambd,limit)
		else:
			print("\nNU SATISFACE Nr:", str(limit))
			print("z = ", str(z))
			print("F(z) = ", str(fz))
			print("Gradientul = ", str(gradz))
			print("Magnitudinea = ", str(magnitz))
			print("---------------------------------------------------------")
			lambd = lambd*omega
			print("Pasul: ", str(lambd))
			rezolv(x1,y1,lambd,limit)

def main():

	rezolv(x0[0],x0[1],lambd,limit=0)

if __name__ == '__main__':
	main()