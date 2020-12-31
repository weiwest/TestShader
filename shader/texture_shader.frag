#version 330 core

out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main ()
{
	FragColor = texture(texture1, TexCoord);
		
//	float r = 0.0f;
//	if(FragColor.r<=0.5f){
//		r = 2*FragColor.r*FragColor.r;
//	}else{
//		r = 1 - 2*(1-FragColor.r)*(1-FragColor.r);
//	}
//	
//	float g = 0.0f;
//	if(FragColor.g<=0.5f){
//		g = 2*FragColor.g*FragColor.g;
//	}else{
//		g = 1 - 2*(1-FragColor.g)*(1-FragColor.g);
//	}
//
//	float b = 0.0f;
//	if(FragColor.b<=0.5f){
//		b = 2*FragColor.b*FragColor.b;
//	}else{
//		b = 1 - 2*(1-FragColor.b)*(1-FragColor.b);
//	}
//
//	float a = 0.0f;
//	if(FragColor.a<=0.5f){
//		a = 2*FragColor.a*FragColor.a;
//	}else{
//		a = 1 - 2*(1-FragColor.a)*(1-FragColor.a);
//	}
	
	//µþ¼Ó
//	float rx = step(0.5f, FragColor.r);
//	float r = abs(rx - 2*(rx-FragColor.r)*(rx-FragColor.r));
//	
//	float gx = step(0.5f, FragColor.g);
//	float g = abs(gx - 2*(gx-FragColor.g)*(gx-FragColor.g));
//	
//	float bx = step(0.5f, FragColor.b);
//	float b = abs(bx - 2*(bx-FragColor.b)*(bx-FragColor.b));
//	
//	float ax = step(0.5f, FragColor.a*0.1f);
//	float a = abs(ax - 2*(ax-FragColor.a)*(ax-FragColor.a*0.1f));

	//Èá¹â
	float ar = 1.0f;
	float br = FragColor.r;
	float r = 0.0f;
	if(br<=0.5f){
		r = 2*ar*br + pow(br, 2)*(1-2*ar) ;
	}else{
		r = 2*br*(1-ar) + sqrt(br)*(2*ar-1);
	}
	
	float ag = 1.0f;
	float bg = FragColor.g;
	float g = 0.0f;
	if(bg<=0.5f){
		g = 2*ag*bg + pow(bg, 2)*(1-2*ag) ;
	}else{
		g = 2*bg*(1-ag) + sqrt(bg)*(2*ag-1);
	}

	float ab = 1.0f;
	float bb = FragColor.b;
	float b = 0.0f;
	if(bb<=0.5f){
		b = 2*ab*bb + pow(bb, 2)*(1-2*ab) ;
	}else{
		b = 2*bb*(1-ab) + sqrt(bb)*(2*ab-1);
	}

	float aa = 1.0f;
	float ba = FragColor.a;
	float a = 0.0f;
	if(ba<=0.5f){
		a = 2*aa*ba + pow(ba, 2)*(1-2*aa) ;
	}else{
		a = 2*ba*(1-aa) + sqrt(ba)*(2*aa-1);
	}


	FragColor = vec4(r,g,b,a);
}