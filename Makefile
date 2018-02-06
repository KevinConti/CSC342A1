###############################################################
#   Students' Makefile for Operating Systems Project          #
#                     Use As Is                               #
###############################################################


# The assignment directory 
ASG_DIR = /home/osp/a1.linux/

# The default C compiler 
C_COMP = gcc 


#make OSP:  


OSP : $(ASG_DIR)osp.o queue.o 
	$(C_COMP) $(ASG_DIR)osp.o queue.o  -lm -g -o OSP

queue.o : queue.c queue.h
	$(C_COMP) -c -g queue.c 


