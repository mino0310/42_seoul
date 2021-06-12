SRCS_PS =	./push_swap_src/push_swap.c \
			./push_swap_src/get_value_in_stack.c \
			./push_swap_src/quick_sort.c \
			./push_swap_src/sort_just_three_a.c \
			./push_swap_src/sort_just_three_b.c \
			./push_swap_src/sort_just_six.c \
			./push_swap_src/sort_less_than_three_a.c \
			./push_swap_src/sort_less_than_three_b.c \
			./push_swap_src/sort_main_a.c \
			./push_swap_src/sort_main_b.c \
			./push_swap_src/get_operation_list.c \
			./push_swap_src/minimize_operation_list.c \
			./push_swap_src/print_operation_list.c \

SRCS_CH =	./checker_src/checker.c \
			./checker_src/get_next_line.c \

SRCS_CM =	./common_src/ft_atoi.c \
			./common_src/ft_strlen.c \
			./common_src/ft_strdup.c \
			./common_src/ft_strcmp.c \
			./common_src/check_argv_to_stack.c \
			./common_src/function_stack.c \
			./common_src/function_operation.c \
			./common_src/operation_process.c \
			./common_src/sorted_check.c \
			./common_src/print_stack_ab.c \
			./common_src/free_stack_operation.c \

NAME_PS = push_swap
NAME_CH = checker
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)
OBJS_CM = $(SRCS_CM:.c=.o)
INCS = .
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all : $(NAME_PS) $(NAME_CH)

$(NAME_PS) : $(OBJS_PS) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) $(OBJS_CM) -I $(INCS)

$(NAME_CH) : $(OBJS_CH) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_CH) $(OBJS_CH) $(OBJS_CM) -I $(INCS)

clean :
		$(RM) $(OBJS_PS) $(OBJS_CH) $(OBJS_CM)

fclean : clean
		$(RM) $(NAME_PS) $(NAME_CH)

re : fclean all

num = 100

push :
		ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG

pushn :
		ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l

check :
		ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG

while_push :
		while true ; do ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG ; sleep 0.5 ; done ;

while_pushn :
		while true ; do ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l ; sleep 0.5 ; done ;

while_check :
		while true ; do ARG=`ruby -e "puts (1..$(num)).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG ; sleep 0.5 ; done ;
