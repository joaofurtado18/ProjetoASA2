rm results.txt
for sz in $(seq 20000 20000 300000); do ./randGeneoTree $sz 0.9 > $sz; done
{ for sz in $(seq 20000 20000 300000); do time ./a.out < $sz; done; } &>> results.txt
