CC			=	clang++
CFLAG		=	-Wall -Werror -Wextra
NAME		=	tester
OBJ_PATH	=	./.obj/
SPATH		=	./
HPATH		=	./../../../includes
RESOURCES	=	./../../../resources/
INC_HPP=$(shell find ./../../.. -name "*.hpp" | rev | cut -d '/' -f2- | rev | sort -u)
INC_PATH=$(INC_HPP)
INC=$(addprefix -I, $(INC_PATH))

SRCS		=	main.cpp testing.cpp ListExecution.cpp VectorExecution.cpp MapExecution.cpp QueueExecution.cpp StackExecution.cpp

OBJS = $(addprefix ${OBJ_PATH}, ${SRCS:.cpp=.o})

ALL:		$(NAME)

$(NAME):		$(OBJS)
		@printf "\033[99D\033[J\033[0;32mCompiling libraries"
		@$(CC) $(CFLAG) $(INC) $(OBJS) -o $(NAME) > log.txt 
	
		@printf "\033[99D\033[J\033[0;32mCompiling objs"
		@printf "\033[99D\033[J\033[0;32mft_contaier TESTER is ready! -> \033[m✅\n"

$(OBJ_PATH)%.o:	$(SPATH)%.cpp
	@mkdir -p ${OBJ_PATH} 
	@printf "\033[99D\033[J\033[0;32m%s" "$<"
	@${CC} ${CFLAG} $(INC) -o $@ -c $< 

clean:
		@rm -rf $(NAME)
		@printf "\033[99D\033[J\033[0;32mClean up TESTER was done. -> \033[m✅\n"

fclean:
		@rm -rf $(NAME) $(OBJ_PATH)
		@printf "\033[99D\033[J\033[0;32mFull clean on TESTER was done. -> \033[m✅\n"

re: fclean $(NAME)
	@printf "\033[99D\033[J\033[0;32mRe-doing TESTER. -> \033[m✅\n"

.PHONY:		clean fclean re