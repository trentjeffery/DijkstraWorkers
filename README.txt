CPSC320A4 is a C++ program written by Trent Jeffery.

The program was written to solve an assignment problem for the UBC course CPSC 320.

The problem is as follows:

"A contractor determines a changing number of qualified workers needed between March and August at one of her/his building sites:
Month:   March April May June July August
Workers:   4     6    7    4    6     2

Workers can be hired or discharged from the building site only at the beginning of the month. Suppose that
in February and in September there must be exactly three workers at the building site.
The aim of the contractor is to plan an allocation of workers (each month, it can be less, exactly or more
than the number of workers needed) which minimizes the sum of the following costs:
• Transfer cost: Hiring a worker to the building site costs $500 and discharging a worker costs $800.
• Transfer rules: The contractor can hire at most 3 workers at a time and can discharge at most one
third of workers at a time (so for example, if there are 6 workers in May, at most 2 of them can be
discharged at the beginning of June, but if there only 5 workers, at most 1 can be discharged).
• Over and under population costs: An extra (idle) worker costs $1000 (per month), whereas a missing
worker costs $2000 (per month). When some stuff is missing, workers take additional working hours,
but they do not accept to work additionally more than 1/4 of their normal time (for example, 3 workers
cannot handle the work of 4 workers, while 4 workers can handle work of 5 workers).
(a) Formulate this problem as a shortest path problem.
Hint. Notice that an optimal solution will never hire more than 7 workers at any month, since at most
7 workers are needed.
(b) Solve it using the Dijsktras algorithm.
Hint. You don’t need to apply Dijkstra algorithm by hand (as the graph will have 17 nodes!). You can
either implement it yourself, or you can download the algorithm from some website (there must be a
plenty of implementations) and use it. If you download the algorithm, remember to cite the source on
the cover page."

(I wrote this program to solve part b)