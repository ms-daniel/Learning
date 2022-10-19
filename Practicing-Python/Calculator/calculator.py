import re
import operations as opr

op = opr.operations()

print('Welcome to the simple calculator!!')
print('This calculator does only one type of operation at a time.')
inp = input('type it\t\t: ')

operator = re.findall(r"[+-/*]", inp)
numbers = re.findall(r"[0-9]+", inp)

print('operador\t:', operator)
print('string para int\t:', numbers)

print('soma\t\t:', op.soma(numbers[0], 2))
print('diferença\t:', op.diferenca(numbers[0], 2))
print('muitiplicação\t:', op.multiplicacao(numbers[0], 2))
print('divisão\t\t:', op.divisao(numbers[0], 2))

