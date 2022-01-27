import matplotlib
matplotlib.use('WebAgg')
import matplotlib.pyplot as plt
import numpy
from sklearn.linear_model import LinearRegression
from matplotlib.ticker import ScalarFormatter

size = []
times = []


file = open("ex2.txt", "r")
for line in file:
    if ("real" in line):
        times += [float(line[10:15])]
    elif (line[:4] not in ("user", "sys ", "sys", "real")):
        size += [int(line)**2]

# lin_reg = LinearRegression()
# lin_reg.fit(size, times)

print(f"times {times}\n size {size}")

class ScalarFormatterClass(ScalarFormatter):
   def _set_format(self):
      self.format = "%1.2f"

x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]

mymodel = numpy.poly1d(numpy.polyfit(size, times, 2))

print(len(size))

myline = numpy.linspace(1, 22, 100)
plt.scatter(size, times)
plt.title("exercício 1")
plt.xlabel("(input_size²) * 10^9")
plt.ylabel("time")
# plt.ticklabel_format(style='plain')
plt.plot(size, times)
ax = plt.gca()
yScalarFormatter = ScalarFormatterClass(useMathText=True)
yScalarFormatter.set_powerlimits((0,0))
ax.yaxis.set_major_formatter(yScalarFormatter)
# plt.plot(myline, mymodel(myline))
plt.show()