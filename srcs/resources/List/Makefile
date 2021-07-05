CC			=	clang++
CFLAG		=	-Wall -Werror -Wextra
NAME		=	container
ORIG		=	container_orig
OBJ_PATH	=	./.obj/
POBJ_MIO	= 	./.obj/mio/
POBJ_ORIG	=	./.obj/orig/


# Paths to main LIST files
SPATH		=	./
HPATH		=	./../../includes
RESOURCES	=	./../../resources/
LIST		=	$(SPATH)main_list_mio.cpp
LIST_ORIG	=	$(SPATH)main_list_original.cpp

INC_HPP=$(shell find ./../.. -name "*.hpp" | rev | cut -d '/' -f2- | rev | sort -u)
INC_PATH=$(INC_HPP)
INC=$(addprefix -I, $(INC_PATH))


OBJS = $(addprefix ${POBJ_MIO}, ${LIST:.cpp=.o})
OBJS_ORIG = $(addprefix ${POBJ_ORIG}, ${LIST_ORIG:.cpp=.o})

ALL:		$(NAME) $(ORIG)

$(NAME):		$(OBJS)
		@printf "\033[99D\033[J\033[0;32mCompiling libraries"
		@$(CC) $(CFLAG) $(INC) $(OBJS) -o $(NAME) > /dev/null 2>&1
		@printf "\033[99D\033[J\033[0;32mCompiling objs"
		@printf "\033[99D\033[J\033[0;32mFT LIST contaier tester is ready! -> \033[m✅\n"

$(POBJ_MIO)%.o:	$(SPATH)%.cpp
	@mkdir -p ${OBJ_PATH}
	@mkdir -p ${POBJ_MIO}
	@printf "\033[99D\033[J\033[0;32m%s" "$<"
	@${CC} ${CFLAG} $(INC) -o $@ -c $< 

$(ORIG):	$(OBJS_ORIG)
	@printf "\033[99D\033[J\033[0;32mCompiling libraries"
	@$(CC) $(CFLAG) $(INC) $(OBJS_ORIG) -o $(ORIG) > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mCompiling objs"
	@printf "\033[99D\033[J\033[0;32mOriginal LIST contaier tester is ready! -> \033[m✅\n"


$(POBJ_ORIG)%.o:	$(SPATH)%.cpp
	@mkdir -p ${POBJ_ORIG}
	@printf "\033[99D\033[J\033[0;32m%s" "$<"
	@${CC} ${CFLAG} $(INC) -o $@ -c $< 

clean:
		@rm -rf $(NAME) $(ORIG)
		@printf "\033[99D\033[J\033[0;32mClean up LIST was done. -> \033[m✅\n"

fclean:
		@rm -rf $(NAME) $(ORIG) $(OBJ_PATH) mio.txt orig.txt
		@printf "\033[99D\033[J\033[0;32mFull clean on LIST was done. -> \033[m✅\n"

re: fclean $(NAME) $(ORIG)
	
	@printf "\033[99D\033[J\033[0;32mRe-doing LIST. -> \033[m✅\n"

.PHONY:		clean fclean re