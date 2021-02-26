#ifndef __PAGINATION_H__
#define __PAGINATION_H__

#define PAGE_SIZE 4096

void	Page_Allocator_init();
void*	Page_Allocator_allocate_pages(int count);

#endif