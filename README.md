# Subject 
Recode the printf function from the C library.
- Convertions to handle : `cspdiuxX%`
- Flags to handle : `-0.*`

# Presentation
Here's my printf remake. I'm only using 2 malloc for the project which is kinda nice. I have a `char[100]` which when it's full will print it's content.
Everytime I convert some value I add the converted string to the buffer using the function `fill_print(t_helper *helper, char c)`. There isn't much to explain here
it's a basic printf and the code should be easy to read as I tried making it the most generic possible.
