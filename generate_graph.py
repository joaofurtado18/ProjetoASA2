import matplotlib
matplotlib.use('WebAgg')
import matplotlib.pyplot as plt
import numpy
#from sklearn.linear_model import LinearRegression
from matplotlib.ticker import ScalarFormatter

size = []
times = []


file = open("results.txt", "r")
for line in file:
    if ("real" in line):
        print(line[7:12])
        times += [float(line[7:12])]
    try:
        size += [int(line)]
    except:
        continue

# lin_reg = LinearRegression()
# lin_reg.fit(size, times)

print(f"times {times}\n size {size}")

class ScalarFormatterClass(ScalarFormatter):
   def _set_format(self):
      self.format = "%1.2f"


mymodel = numpy.poly1d(numpy.polyfit(size, times, 2))

print(len(size), len(times))

myline = numpy.linspace(1, 22, 100)
plt.scatter(size, times)
plt.title("Lowest Common Ancestor")
plt.xlabel("input_size")
plt.ylabel("time")
plt.ticklabel_format(style='plain')
plt.plot(size, times)
ax = plt.gca()
ax.ticklabel_format(useOffset=False)
yScalarFormatter = ScalarFormatterClass(useMathText=True)
yScalarFormatter.set_powerlimits((0,0))
ax.yaxis.set_major_formatter(yScalarFormatter)
# plt.plot(myline, mymodel(myline))
plt.show()
