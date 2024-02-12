for i in {1..200}
do
	ARG=$(python3 ./push_swap_tester/push_swap_tester.py --gen -l 500) && ./push_swap $ARG | wc -l | bc
done
