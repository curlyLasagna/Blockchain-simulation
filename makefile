CC:=g++
CFLAGS:=-Wall 
OBJDIR:=obj
OBJ=block.o main.o
TARGET:=blockChain
DEPS:= BinaryTree.h TreeNode.h block.h

#$(OBJ):|$(OBJDIR)
#
#$(OBJDIR):
#	mkdir $(OBJDIR)

#$(OBJDIR)/%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS) 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 


$(TARGET): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY: clean 

clean:
	rm $(OBJ) $(TARGET)
