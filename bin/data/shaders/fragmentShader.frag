
//uniform float time 
uniform	vec2 minPoint;
uniform vec2 maxPoint;
uniform float time;

vec2 ComplexMul(vec2 v0, vec2 v1)
{
	return vec2(v0.x*v1.x - v0.y*v1.y, v0.x*v1.y + v0.y*v1.x);
}

float GetMandelbrot(vec2 point)
{
	float maxIterations = 1000.0;
	float i = 0.0;
	vec2 currPoint = point;
	while (i < maxIterations && length(currPoint) < 10000.0)
	{
		i++;
//		currPoint = ComplexMul(currPoint, currPoint) + point;
		currPoint = ComplexMul(currPoint, currPoint) + vec2(-0.8+0.01*sin(time), 0.156);
	}
	return i / maxIterations;
}


void main() //всегда void
{
	
	vec2 windowSize = vec2(300.0, 300.0);
	vec2 complexCoord = minPoint + (maxPoint - minPoint) * gl_FragCoord.xy / windowSize;

	float value = GetMandelbrot(complexCoord);
	value = 1.0 - pow(1 - value, 10.0);
	gl_FragColor = vec4(vec3(value), 1.0);
}