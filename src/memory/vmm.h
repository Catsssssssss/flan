#ifndef vmm_h
#define vmm_h
#include <stdint.h>

typedef struct{
    uint64_t top;
} pagemap_t;

void vmm_init();
void vmm_switch_pagemap(pagemap_t* pagemap);
void vmm_map_page(pagemap_t* pagemap, uint64_t physical_address, uint64_t virtual_address, uint64_t flags);
void vmm_unmap_page(pagemap_t* pagemap, uint64_t virtual_address);
pagemap_t*  new_pagemap();
pagemap_t vmm_new_pagemap();


extern volatile struct limine_hhdm_request hhdm_request;
#define HHDM_OFFSET (hhdm_request.response->offset)
extern pagemap_t* kernel_pagemap;
#endif