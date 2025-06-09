#target : dependency files.o
a.out : main1.o add_begin.o add_end.o print_data.o
	cc main1.o add_begin.o add_end.o print_data.o
main1.o : main1.c
	cc -c main1.c
add_begin.o : add_begin.c
	cc -c add_begin.c
add_end.o : add_end.c
	cc -c add_end.c
print_data.o : print_data.c
	cc -c print_data.c
clear :
	@echo "cleaning up.."
	@rm -r *.o
