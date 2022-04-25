f(x) = for digit : digits -> min(f(x - digit) + 1)
f(0) = 0;

There can be overlapping subproblem

Bottom-up 
for (i = 1 to x)
Don't Need extra space - Max we need to look back to 9th number