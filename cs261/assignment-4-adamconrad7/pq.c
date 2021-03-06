/ * 
   *   I n   t h i s   f i l e ,   y o u   w i l l   w r i t e   t h e   s t r u c t u r e s   a n d   f u n c t i o n s   n e e d e d   t o 
   *   i m p l e m e n t   a   p r i o r i t y   q u e u e .     F e e l   f r e e   t o   i m p l e m e n t   a n y   h e l p e r   f u n c t i o n s 
   *   y o u   n e e d   i n   t h i s   f i l e   t o   i m p l e m e n t   a   p r i o r i t y   q u e u e .     M a k e   s u r e   t o   a d d   y o u r 
   *   n a m e   a n d   @ o r e g o n s t a t e . e d u   e m a i l   a d d r e s s   b e l o w : 
   * 
   *   N a m e :   A d a m   C o n r a d 
   *   E m a i l :   c o n r a a d a @ o r e g o n s t a t e . e d u 
   * / 
 
 # i n c l u d e   < s t d l i b . h > 
 # i n c l u d e   < s t d i o . h > 
 # i n c l u d e   < m a t h . h > 
 # i n c l u d e   " p q . h " 
 # i n c l u d e   " d y n a r r a y . h " 
 
 / * 
   *   T h i s   i s   t h e   s t r u c t u r e   t h a t   r e p r e s e n t s   a   p r i o r i t y   q u e u e .     Y o u   m u s t   d e f i n e 
   *   t h i s   s t r u c t   t o   c o n t a i n   t h e   d a t a   n e e d e d   t o   i m p l e m e n t   a   p r i o r i t y   q u e u e . 
   * / 
 s t r u c t   p q { 
     s t r u c t   d y n a r r a y *   a r r ; 
 } ; 
 
 s t r u c t   i t e m   { 
       v o i d *   v a l ; 
       i n t   k e y ; 
 } ; 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   a l l o c a t e   a n d   i n i t i a l i z e   a n   e m p t y   p r i o r i t y   q u e u e   a n d 
   *   r e t u r n   a   p o i n t e r   t o   i t . 
   * / 
 s t r u c t   p q *   p q _ c r e a t e ( )   { 
 / /     p r i n t f ( " A l l o c a t i n g   p q \ n " ) ; 
     s t r u c t   p q *   p q p   =   m a l l o c ( s i z e o f ( s t r u c t   p q ) ) ; 
     p q p   - >   a r r   =   d y n a r r a y _ c r e a t e ( ) ; 
     r e t u r n   p q p ; 
 } 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   f r e e   t h e   m e m o r y   a l l o c a t e d   t o   a   g i v e n   p r i o r i t y   q u e u e . 
   *   N o t e   t h a t   t h i s   f u n c t i o n   S H O U L D   N O T   f r e e   t h e   i n d i v i d u a l   e l e m e n t s   s t o r e d   i n 
   *   t h e   p r i o r i t y   q u e u e .     T h a t   i s   t h e   r e s p o n s i b i l i t y   o f   t h e   c a l l e r . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   t o   b e   d e s t r o y e d .     M a y   n o t   b e   N U L L . 
   * / 
 v o i d   p q _ f r e e ( s t r u c t   p q *   p q )   { 
     f o r ( i n t   i = 0 ;   i < d y n a r r a y _ s i z e (   p q   - >   a r r ) ;   i + + ) { 
         s t r u c t   i t e m *   n o d e   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   i ) ; 
         f r e e ( n o d e ) ; 
     } 
     d y n a r r a y _ f r e e ( p q   - >   a r r ) ; 
     f r e e ( p q ) ; 
     r e t u r n ; 
 } 
 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   r e t u r n   1   i f   t h e   s p e c i f i e d   p r i o r i t y   q u e u e   i s   e m p t y   a n d 
   *   0   o t h e r w i s e . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   w h o s e   e m p t i n e s s   i s   t o   b e   c h e c k e d .     M a y   n o t   b e 
   *           N U L L . 
   * 
   *   R e t u r n : 
   *       S h o u l d   r e t u r n   1   i f   p q   i s   e m p t y   a n d   0   o t h e r w i s e . 
   * / 
 i n t   p q _ i s e m p t y ( s t r u c t   p q *   p q )   { 
     i f ( d y n a r r a y _ s i z e (   p q   - >   a r r )   = =   0 ) { 
         r e t u r n   1 ; 
     } e l s e { 
         r e t u r n   0 ; 
     } 
 } 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   i n s e r t   a   g i v e n   e l e m e n t   i n t o   a   p r i o r i t y   q u e u e   w i t h   a 
   *   s p e c i f i e d   p r i o r i t y   v a l u e .     N o t e   t h a t   i n   t h i s   i m p l e m e n t a t i o n ,   L O W E R   p r i o r i t y 
   *   v a l u e s   a r e   a s s i g n e d   t o   e l e m e n t s   w i t h   H I G H E R   p r i o r i t y .     I n   o t h e r   w o r d s ,   t h e 
   *   e l e m e n t   i n   t h e   p r i o r i t y   q u e u e   w i t h   t h e   L O W E S T   p r i o r i t y   v a l u e   s h o u l d   b e   t h e 
   *   F I R S T   o n e   r e t u r n e d . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   i n t o   w h i c h   t o   i n s e r t   a n   e l e m e n t .     M a y   n o t   b e 
   *           N U L L . 
   *       v a l u e   -   t h e   v a l u e   t o   b e   i n s e r t e d   i n t o   p q . 
   *       p r i o r i t y   -   t h e   p r i o r i t y   v a l u e   t o   b e   a s s i g n e d   t o   t h e   n e w l y - i n s e r t e d 
   *           e l e m e n t .     N o t e   t h a t   i n   t h i s   i m p l e m e n t a t i o n ,   L O W E R   p r i o r i t y   v a l u e s 
   *           s h o u l d   c o r r e s p o n d   t o   e l e m e n t s   w i t h   H I G H E R   p r i o r i t y .     I n   o t h e r   w o r d s , 
   *           t h e   e l e m e n t   i n   t h e   p r i o r i t y   q u e u e   w i t h   t h e   L O W E S T   p r i o r i t y   v a l u e   s h o u l d 
   *           b e   t h e   F I R S T   o n e   r e t u r n e d . 
   * / 
 v o i d   p q _ i n s e r t ( s t r u c t   p q *   p q ,   v o i d *   v a l u e ,   i n t   p r i o r i t y )   { 
 / /     p r i n t f ( " A l l o c a t i n g   n e w   n o d e \ n " ) ; 
     s t r u c t   i t e m *   n o d e   =   m a l l o c ( s i z e o f ( s t r u c t   i t e m ) ) ; 
     n o d e   - >   v a l   =   v a l u e ; 
     n o d e   - >   k e y   =   p r i o r i t y ; 
     d y n a r r a y _ i n s e r t ( p q   - >   a r r ,   n o d e ) ; 
     b u b b l e ( p q ,   d y n a r r a y _ s i z e (   p q   - >   a r r ) - 1   ) ; 
     r e t u r n ; 
 } 
 
 
     / * 
   *   T h i s   f u n c t i o n   s h o u l d   r e t u r n   t h e   v a l u e   o f   t h e   f i r s t   i t e m   i n   a   p r i o r i t y 
   *   q u e u e ,   i . e .   t h e   i t e m   w i t h   L O W E S T   p r i o r i t y   v a l u e . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   f r o m   w h i c h   t o   f e t c h   a   v a l u e .     M a y   n o t   b e   N U L L   o r 
   *           e m p t y . 
   * 
   *   R e t u r n : 
   *       S h o u l d   r e t u r n   t h e   v a l u e   o f   t h e   f i r s t   i t e m   i n   p q ,   i . e .   t h e   i t e m   w i t h 
   *       L O W E S T   p r i o r i t y   v a l u e . 
   * / 
 v o i d *   p q _ f i r s t ( s t r u c t   p q *   p q )   { 
     s t r u c t   i t e m *   n o d e   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   0 ) ; 
     r e t u r n   n o d e   - >   v a l ; 
 } 
 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   r e t u r n   t h e   p r i o r i t y   v a l u e   o f   t h e   f i r s t   i t e m   i n   a 
   *   p r i o r i t y   q u e u e ,   i . e .   t h e   i t e m   w i t h   L O W E S T   p r i o r i t y   v a l u e . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   f r o m   w h i c h   t o   f e t c h   a   p r i o r i t y   v a l u e .     M a y   n o t   b e 
   *           N U L L   o r   e m p t y . 
   * 
   *   R e t u r n : 
   *       S h o u l d   r e t u r n   t h e   p r i o r i t y   v a l u e   o f   t h e   f i r s t   i t e m   i n   p q ,   i . e .   t h e   i t e m 
   *       w i t h   L O W E S T   p r i o r i t y   v a l u e . 
   * / 
 i n t   p q _ f i r s t _ p r i o r i t y ( s t r u c t   p q *   p q )   { 
     s t r u c t   i t e m *   n o d e   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   0 ) ; / /   f a i l s   a s s e r t i o n   s e c o n d   t i m e   b u t   n o t   f i r s t ? 
     r e t u r n   n o d e   - >   k e y ; 
 } 
 
 
 / * 
   *   T h i s   f u n c t i o n   s h o u l d   r e t u r n   t h e   v a l u e   o f   t h e   f i r s t   i t e m   i n   a   p r i o r i t y 
   *   q u e u e ,   i . e .   t h e   i t e m   w i t h   L O W E S T   p r i o r i t y   v a l u e ,   a n d   t h e n   r e m o v e   t h a t   i t e m 
   *   f r o m   t h e   q u e u e . 
   * 
   *   P a r a m s : 
   *       p q   -   t h e   p r i o r i t y   q u e u e   f r o m   w h i c h   t o   r e m o v e   a   v a l u e .     M a y   n o t   b e   N U L L   o r 
   *           e m p t y . 
   * 
   *   R e t u r n : 
   *       S h o u l d   r e t u r n   t h e   v a l u e   o f   t h e   f i r s t   i t e m   i n   p q ,   i . e .   t h e   i t e m   w i t h 
   *       L O W E S T   p r i o r i t y   v a l u e . 
   * / 
 v o i d *   p q _ r e m o v e _ f i r s t ( s t r u c t   p q *   p q )   { 
     / / r e m o v e   g e t   l o w e s t   e l e m e n t   (   [ 0 ]   o f   a r r a y   ) 
         / / d y n a r r y   w i l l   s h i f t   a l l   e l e m e n t s   b e y o n d   i n d e x   a f t e r   r e m o v a l 
     / / s e t   f i r s t   e l e m e n t   t o   l a s t   e l e m e n t 
     / / d e l e t e   l a s t   e l e m e n t 
     s t r u c t   i t e m *   n o d e   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   0 ) ; 
     s t r u c t   i t e m *   l a s t   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   d y n a r r a y _ s i z e (   p q   - >   a r r ) - 1   ) ; 
     / / f r e e ( n o d e ) ; 
     v o i d   *   v a l   =   n o d e   - >   v a l ; 
     f r e e ( n o d e ) ; 
     d y n a r r a y _ s e t (   p q   - >   a r r ,   0 ,   l a s t ) ; 
     d y n a r r a y _ r e m o v e (   p q   - >   a r r ,   d y n a r r a y _ s i z e (   p q   - >   a r r ) - 1 ) ; 
     h e a p i f y (   p q   ,   0 ) ; 
     r e t u r n   v a l ; 
 } 
 
 / / C U S T O M   f u n c t i o n s 
 v o i d   s w a p (   s t r u c t   p q *   p q ,   i n t   i 1 ,   i n t   i 2 ) { 
     s t r u c t   i t e m *   t m p   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   i 1 ) ;   / /   i t e m   1   s t o r e d   i n   t m p 
     s t r u c t   i t e m *   t m p 2   =   d y n a r r a y _ g e t (   p q   - >   a r r ,   i 2 ) ;   / /   i t e m   2   s t o r e d   i n   t m p 2 
     d y n a r r a y _ s e t (   p q   - >   a r r ,   i 1 ,   t m p 2 ) ;   / /   s e t   i t e m   1   t o   i t e m   2 
     d y n a r r a y _ s e t (   p q   - >   a r r ,   i 2 ,   t m p ) ;   / /   s e t   i t e m   2   t o   i t e m   1 
 } 
 
 v o i d   b u b b l e ( s t r u c t   p q *   p q ,   i n t   i ) { 
     s t r u c t   d y n a r r a y *   a r r   =   p q   - >   a r r ; 
     i n t   p   =   ( i - 1 )   /   2 ; 
     w h i l e (     ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   i ) ) - >   k e y   <   ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   p ) ) - >   k e y   ) { 
         s w a p ( p q ,   i ,   p ) ; 
         i   =   p ; 
         p   =   ( i - 1 )   /   2 ; 
     } 
 } 
 
 v o i d   h e a p i f y (   s t r u c t   p q *   p q ,   i n t   p e r c i d x ) { 
     s t r u c t   d y n a r r a y *   a r r   =   p q   - >   a r r ; 
     i n t   l e f t   =   2   *   p e r c i d x   +   1 ; 
     i n t   r i g h t   =   l e f t   +   1 ; 
     i n t   s m a l l e s t   =   p e r c i d x ; 
 
     / / i f   i n d e x   o f   l e f t   c h i l d   i s   w i t h i n   t h e   a r r a y   a n d   l e f t   c h i l d ' s   k e y   i s   l e s s   t h a n   p a r e n t s   k e y : 
     i f (   l e f t   <   d y n a r r a y _ s i z e ( a r r )   & &   ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   l e f t ) )   - >   k e y   <   ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   p e r c i d x ) )   - >   k e y ) 
         s m a l l e s t   =   l e f t ; 
     i f (   r i g h t   <   d y n a r r a y _ s i z e ( a r r )   & &   ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   r i g h t ) )   - >   k e y   <   ( ( s t r u c t   i t e m * ) d y n a r r a y _ g e t (   a r r ,   s m a l l e s t ) )   - >   k e y ) 
         s m a l l e s t   =   r i g h t ; 
     i f (   s m a l l e s t   ! =   p e r c i d x ) { 
         s w a p ( p q ,   p e r c i d x ,   s m a l l e s t ) ; 
         h e a p i f y ( p q ,   s m a l l e s t ) ; 
     } 
 } 
 