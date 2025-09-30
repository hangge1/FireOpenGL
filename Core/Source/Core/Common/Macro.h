

#define DELETE_COPY_ASSIGNMENT(Class) \
    Class(const Class&) = delete; \
    Class& operator=(const Class&) = delete;
