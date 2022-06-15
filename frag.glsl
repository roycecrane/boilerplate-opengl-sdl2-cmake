# version 460
 in vec3 fpos;
 out vec4 out_color;
 float maxIterations = 20;
 vec2 squareImaginary(vec2 number){
 	return vec2(
 		pow(number.x,2) - pow(number.y,2), 2*number.x*number.y );
 }
 float iterateMandelbrot(vec2 coord,in out float L){
 	vec2 z = vec2(0,0);
 	for(int i=0;i<maxIterations;i++){
 		z = squareImaginary(z) + coord;
		L = length(z);
 		if(L>1.5) return i/maxIterations;
 	}
 	return maxIterations;
 }
 void main(){
     vec2 p = fpos.xy;
	 float L = 0.0 ;
     float col = iterateMandelbrot(p,L);
     out_color = vec4(L,0,col,0);
 }