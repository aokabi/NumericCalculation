set terminal x11

set datafile separator ','

plot 'locust.csv' using 1:2 with lines,\
'locust.csv' using 1:3 with lines,\
'locust.csv' using 1:4 with lines,\
'locust.csv' using 1:5 with lines,\
'locust.csv' using 1:6 with lines,\
'locust.csv' using 1:7 with lines,\
'locust.csv' using 1:8 with lines
pause -1
