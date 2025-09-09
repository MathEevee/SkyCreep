SRCDIR		:= ./src
OBJDIR		:= ./obj

NAME	:= change_data
CC		:= c++
SRCS 	:= file.cpp item.cpp itemType.cpp price.cpp rank.cpp main.cpp
OBJS	:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	@$(CC) -o $@ -c $< && printf "$(GREEN)✔️ $(notdir $<) compiled\n"

$(OBJDIRB)/%.o: $(SRCDIRB)/%.cpp
	@test -d $(OBJDIRB) || mkdir $(OBJDIRB)
	@$(CC) -o $@ -c $< && printf "$(GREEN)✔️ $(notdir $<) compiled\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIRB)

fclean: clean
	@rm -rf $(NAME)

cleanb: 
	@rm -rf $(OBJDIRB)

re: clean all

.PHONY: all, clean, fclean, re