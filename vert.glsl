# version 460
in vec3 pos;
out vec3 fpos;
void main(){
    gl_Position = vec4(pos, 1.0);
    fpos = pos;
}

