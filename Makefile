CC			=	clang++
CFLAG		=	-Wall -Werror -Wextra
NAME		=	container
TESTER		=	tester
OBJ_PATH	=	./.obj/

LIST		=	./srcs/resources/List
MAP			=	./srcs/resources/Map
QUEUE		=	./srcs/resources/Queue
STACK		=	./srcs/resources/Stack
VECTOR		=	./srcs/resources/Vector

TPATH		=	./srcs/resources/Ztests/mytest/
SPATH		=	./srcs/containers/
HPATH		=	./srcs/includes/
RESOURCES	=	./srcs/resources/
INC_HPP=$(shell find . -name "*.hpp" | rev | cut -d '/' -f2- | rev | sort -u)
INC_PATH=$(INC_HPP)
INC=$(addprefix -I, $(INC_PATH))

OBJS_LIST	=	$(SRCS_LIST:.cpp=.o)

$(SPATH)%.o:	%.c
	$(CC) $(CFLAG) -c $‹

ALL:		$(TESTER)

$(TESTER): list vector map stack queue
		@make -C $(TPATH)
		@cp $(TPATH)$(TESTER) .
test:
	@make -C $(TPATH)
	@cp $(TPATH)$(TESTER) .

list:
	@make -C $(LIST)

vector:
	@make -C $(VECTOR)

map:
	@make -C $(MAP)

stack:
	@make -C $(STACK)

queue:
	@make -C $(QUEUE)

clean:
		@rm -rf $(TESTER)
		@make clean -C $(TPATH)
		@make clean -C $(LIST)
		@make clean -C $(MAP)
		@make clean -C $(QUEUE)
		@make clean -C $(STACK)
		@make clean -C $(VECTOR)

fclean:
		@rm -rf $(TESTER) $(OBJS)
		@make fclean -C $(TPATH)
		@make fclean -C $(LIST)
		@make fclean -C $(MAP)
		@make fclean -C $(QUEUE)
		@make fclean -C $(STACK)
		@make fclean -C $(VECTOR)
		

re:	fclean $(TESTER) list map queue stack vector

check:
	@make list > /dev/null 2>&1
	./scripts/tester.sh
	@make fclean > /dev/null 2>&1
	@make vector > /dev/null 2>&1
	./scripts/tester.sh
	@make fclean > /dev/null 2>&1
	@make map > /dev/null 2>&1
	./scripts/tester.sh
	@make fclean > /dev/null 2>&1
	@make stack > /dev/null 2>&1
	./scripts/tester.sh
	@make fclean > /dev/null 2>&1
	@make queue > /dev/null 2>&1
	./scripts/tester.sh

.PHONY:		clean fclean re