//Generated with Symbolize (c) 2019 Alexander Kraus <nr4@z10.info>.
#ifndef SYMBOLIZE_H
#define SYMBOLIZE_H

extern float progress;int rand_handle, hash11_handle, hash12_handle, hash21_handle, hash22_handle, hash31_handle, stroke_handle, lfnoise_handle, dvoronoi_handle, dbox_handle, dlinesegment_handle, smoothmin_handle, add_handle, normal_handle, dbox3_handle, rot3_handle, dbox210_handle, dspline2_handle, zextrude_handle, mfnoise_handle, rshort_handle, rfloat_handle, dcircle_handle, drhomboid_handle, dcirclesegment_handle, dglyph_handle, dstring_handle, dfloat_handle, dint_handle, dtime_handle, addwindow_handle, ddeadline_handle, dpolygon_handle, dspacepigs_handle, analytical_box_handle, hash33_handle, dvoronoi3_handle, dsmoothvoronoi3_handle, dstar_handle, smoothmax_handle, dstar3_handle, dhexagonpattern_handle, dmercury_handle, dtriangle_handle, rot_handle, dschnappsgirls_handle, dhaujobb_handle, dkewlers_handle, dfarbrausch_handle, d5711_handle, sub_handle, doctahedron_handle;
const int nsymbols = 52;
const char *rand_source = "#version 130\n\n"
"void rand(in vec2 x, out float n)\n"
"{\n"
"    x += 400.;\n"
"    n = fract(sin(dot(sign(x)*abs(x) ,vec2(12.9898,78.233)))*43758.5453);\n"
"}\n"
"\0";
const char *hash11_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash11(in float p, out float d)\n"
"{\n"
"    p = fract(p * .1031);\n"
"    p *= p + 33.33;\n"
"    p *= p + p;\n"
"    d = fract(p);\n"
"}\n"
"\0";
const char *hash12_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash12(in vec2 p, out float d)\n"
"{\n"
"	vec3 p3  = fract(vec3(p.xyx) * .1031);\n"
"    p3 += dot(p3, p3.yzx + 33.33);\n"
"    d = fract((p3.x + p3.y) * p3.z);\n"
"}\n"
"\0";
const char *hash21_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash21(in float p, out vec2 d)\n"
"{\n"
"	vec3 p3 = fract(vec3(p) * vec3(.1031, .1030, .0973));\n"
"	p3 += dot(p3, p3.yzx + 33.33);\n"
"    d = fract((p3.xx+p3.yz)*p3.zy);\n"
"}\n"
"\0";
const char *hash22_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash22(in vec2 p, out vec2 d)\n"
"{\n"
"	vec3 p3 = fract(vec3(p.xyx) * vec3(.1031, .1030, .0973));\n"
"    p3 += dot(p3, p3.yzx+33.33);\n"
"    d = fract((p3.xx+p3.yz)*p3.zy);\n"
"}\n"
"\0";
const char *hash31_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash31(in float p, out vec3 d)\n"
"{\n"
"   vec3 p3 = fract(vec3(p) * vec3(.1031, .1030, .0973));\n"
"   p3 += dot(p3, p3.yzx+33.33);\n"
"   d = fract((p3.xxy+p3.yzz)*p3.zyx); \n"
"}\n"
"\0";
const char *stroke_source = "// Stroke\n"
"void stroke(in float d0, in float s, out float d)\n"
"{\n"
"    d = abs(d0)-s;\n"
"}\n"
"\0";
const char *lfnoise_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void rand(in vec2 x, out float d);\n"
"void lfnoise(in vec2 t, out float n)\n"
"{\n"
"    vec2 i = floor(t);\n"
"    t = fract(t);\n"
"    t = smoothstep(c.yy, c.xx, t);\n"
"    vec2 v1, v2;\n"
"    rand(i, v1.x);\n"
"    rand(i+c.xy, v1.y);\n"
"    rand(i+c.yx, v2.x);\n"
"    rand(i+c.xx, v2.y);\n"
"    v1 = c.zz+2.*mix(v1, v2, t.y);\n"
"    n = mix(v1.x, v1.y, t.x);\n"
"}\n"
"\0";
const char *dvoronoi_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void hash22(in vec2 a, out vec2 b);\n"
"void dist(in vec2 a, in vec2 b, out float d)\n"
"{\n"
"    d = length(b-a);\n"
"}\n"
"\n"
"void nearest_controlpoint(in vec2 x, out vec2 p)\n"
"{\n"
"    float dmin = 1.e5, \n"
"        d;\n"
"    vec2 dp,\n"
"        y = floor(x);\n"
"    \n"
"    float i = 0.;\n"
"    for(float i = -1.; i <= 1.; i += 1.)\n"
"        for(float j = -1.; j <= 1.; j += 1.)\n"
"        {\n"
"            hash22(y+vec2(i,j), dp);\n"
"            dp += y+vec2(i,j);\n"
"            dist(x, dp, d);\n"
"            if(d<dmin)\n"
"            {\n"
"                dmin = d;\n"
"                p = dp;\n"
"            }\n"
"        }\n"
"}\n"
"\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance)\n"
"{\n"
"    d = 1.e4;\n"
"    vec2 y,\n"
"        dp;\n"
"    \n"
"    nearest_controlpoint(x, p);\n"
"    y = floor(p);\n"
"    \n"
"    control_distance = 1.e4;\n"
"    \n"
"    for(float i = -2.; i <= 2.; i += 1.)\n"
"        for(float j = -2.; j <= 2.; j += 1.)\n"
"        {\n"
"            if(i==0. && j==0.) continue;\n"
"            hash22(y+vec2(i,j), dp);\n"
"            dp += y+vec2(i,j);\n"
"            vec2 o = p - dp;\n"
"            float l = length(o);\n"
"            d = min(d,abs(.5*l-dot(x-dp,o)/l));\n"
"            control_distance = min(control_distance,.5*l);\n"
"        }\n"
"}\n"
"\0";
const char *dbox_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void dbox(in vec2 x, in vec2 b, out float d)\n"
"{\n"
"    vec2 da = abs(x)-b;\n"
"    d = length(max(da,c.yy)) + min(max(da.x,da.y),0.0);\n"
"}\n"
"\0";
const char *dlinesegment_source = "#version 130\n\n"
"\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d)\n"
"{\n"
"    vec2 da = p2-p1;\n"
"    d = length(x-mix(p1, p2, clamp(dot(x-p1, da)/dot(da,da),0.,1.)));\n"
"}\n"
"\0";
const char *smoothmin_source = "// iq's smooth minimum\n"
"void smoothmin(in float a, in float b, in float k, out float dst)\n"
"{\n"
"    float h = max( k-abs(a-b), 0.0 )/k;\n"
"    dst = min( a, b ) - h*h*h*k*(1.0/6.0);\n"
"}\n"
"\0";
const char *add_source = "void add(in vec2 sda, in vec2 sdb, out vec2 sdf)\n"
"{\n"
"    sdf = (sda.x<sdb.x)?sda:sdb;\n"
"}\n"
"\0";
const char *normal_source = "const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"void scene(in vec3 x, out vec2 s);\n"
"void normal(in vec3 x, out vec3 n, in float dx)\n"
"{\n"
"    vec2 s, na;\n"
"    \n"
"    scene(x,s);\n"
"    scene(x+dx*c.xyy, na);\n"
"    n.x = na.x;\n"
"    scene(x+dx*c.yxy, na);\n"
"    n.y = na.x;\n"
"    scene(x+dx*c.yyx, na);\n"
"    n.z = na.x;\n"
"    n = normalize(n-s.x);\n"
"}\n"
"\0";
const char *dbox3_source = "#version 130\n\n"
"void dbox3(in vec3 x, in vec3 b, out float d)\n"
"{\n"
"  vec3 da = abs(x) - b;\n"
"  d = length(max(da,0.0))\n"
"         + min(max(da.x,max(da.y,da.z)),0.0);\n"
"}\n"
"\0";
const char *rot3_source = "const vec3 c = vec3(1.,0.,-1.);\n"
"void rot3(in vec3 p, out mat3 rot)\n"
"{\n"
"    rot = mat3(c.xyyy, cos(p.x), sin(p.x), 0., -sin(p.x), cos(p.x))\n"
"        *mat3(cos(p.y), 0., -sin(p.y), c.yxy, sin(p.y), 0., cos(p.y))\n"
"        *mat3(cos(p.z), -sin(p.z), 0., sin(p.z), cos(p.z), c.yyyx);\n"
"}\n"
"\0";
const char *dbox210_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"\n"
"void dbox210(in vec3 x, in float size, out vec2 sdf)\n"
"{\n"
"    x /= size;\n"
"    \n"
"    float d = 1.;\n"
"    \n"
"    // Big red box    \n"
"    dbox3(x, .2*c.xxx, sdf.x);\n"
"    sdf.y = 1.;\n"
"    \n"
"    // Holes\n"
"    \n"
"    // 2 upper bar\n"
"    dbox3(x-.1*c.xyy, vec3(.02,.3,.12), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 right bar\n"
"    dbox3(x-.05*c.xyy-.1*c.yyx, vec3(.07,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 mid bar\n"
"    dbox3(x, vec3(.02,.3,.1), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 left bar\n"
"    dbox3(x+.05*c.xyy+.1*c.yyx, vec3(.07,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 dot\n"
"    dbox3(x+.1*c.xyy-.1*c.yyx, vec3(.02,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 1 bar\n"
"    dbox3(x+.04*c.yyx, vec3(.3,.02,.08), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 1 dot\n"
"    dbox3(x-.1*c.yyx, vec3(.3,.02,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 0 big stripes\n"
"    vec3 y = vec3(x.x, abs(x.y), x.z);\n"
"    dbox3(y-.05*c.yxy, vec3(.1,.03,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"\n"
"	// 0 small stripes\n"
"    dbox3(y-.1*c.yxy-.06*c.xyy, vec3(.08,.021,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"\n"
"    // 0 upper/lower stripes\n"
"    vec3 z = vec3(abs(x.x), x.yz);\n"
"	dbox3(z-.119*c.xyy, vec3(.021,.08,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    sdf.x *= size;\n"
"}\n"
"\0";
const char *dspline2_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"const float pi = acos(-1.);\n"
"\n"
"//distance to spline with parameter t\n"
"float dist2(vec2 p0,vec2 p1,vec2 p2,vec2 x,float t)\n"
"{\n"
"    t = clamp(t, 0., 1.);\n"
"    return length(x-pow(1.-t,2.)*p0-2.*(1.-t)*t*p1-t*t*p2);\n"
"}\n"
"\n"
"//minimum dist3ance to spline\n"
"void dspline2(in vec2 x, in vec2 p0, in vec2 p1, in vec2 p2, out float ds)\n"
"{\n"
"    //coefficients for 0 = t^3 + a * t^2 + b * t + c\n"
"    vec2 E = x-p0, F = p2-2.*p1+p0, G = p1-p0;\n"
"    vec3 ai = vec3(3.*dot(G,F), 2.*dot(G,G)-dot(E,F), -dot(E,G))/dot(F,F);\n"
"\n"
"	//discriminant and helpers\n"
"    float tau = ai.x/3., p = ai.y-tau*ai.x, q = - tau*(tau*tau+p)+ai.z, dis = q*q/4.+p*p*p/27.;\n"
"    \n"
"    //triple real root\n"
"    if(dis > 0.) \n"
"    {\n"
"        vec2 ki = -.5*q*c.xx+sqrt(dis)*c.xz, ui = sign(ki)*pow(abs(ki), c.xx/3.);\n"
"        ds = dist2(p0,p1,p2,x,ui.x+ui.y-tau);\n"
"        return;\n"
"    }\n"
"    \n"
"    //three dist3inct real roots\n"
"    float fac = sqrt(-4./3.*p), arg = acos(-.5*q*sqrt(-27./p/p/p))/3.;\n"
"    vec3 t = c.zxz*fac*cos(arg*c.xxx+c*pi/3.)-tau;\n"
"    ds = min(\n"
"        dist2(p0,p1,p2,x, t.x),\n"
"        min(\n"
"            dist2(p0,p1,p2,x,t.y),\n"
"            dist2(p0,p1,p2,x,t.z)\n"
"        )\n"
"    );\n"
"}\n"
"\0";
const char *zextrude_source = "// Extrusion\n"
"void zextrude(in float z, in float d2d, in float h, out float d)\n"
"{\n"
"    vec2 w = vec2(-d2d, abs(z)-0.5*h);\n"
"    d = length(max(w,0.0));\n"
"}\n"
"\0";
const char *mfnoise_source = "#version 130\n\n"
"// const vec3 c = vec3(1.,0.,-1.);\n"
"void lfnoise(in vec2 x, out float d);\n"
"void mfnoise(in vec2 x, in float d, in float b, in float e, out float n)\n"
"{\n"
"    n = 0.;\n"
"    float a = 1., nf = 0., buf;\n"
"    for(float f = d; f<b; f *= 2.)\n"
"    {\n"
"        lfnoise(f*x, buf);\n"
"        n += a*buf;\n"
"        a *= e;\n"
"        nf += 1.;\n"
"    }\n"
"    n *= (1.-e)/(1.-pow(e, nf));\n"
"}\n"
"\0";
const char *rshort_source = "#version 130\n\n"
"\n"
"uniform float iFontWidth;\n"
"uniform sampler2D iFont;\n"
"\n"
"void rshort(in float off, out float val)\n"
"{\n"
"    // Parity of offset determines which byte is required.\n"
"    float hilo = mod(off, 2.);\n"
"    // Find the pixel offset your data is in (2 unsigned shorts per pixel).\n"
"    off *= .5;\n"
"    // - Determine texture coordinates.\n"
"    //     offset = i*iFontWidth+j for (i,j) in [0,iFontWidth]^2\n"
"    //     floor(offset/iFontWidth) = floor((i*iFontwidth+j)/iFontwidth)\n"
"    //                              = floor(i)+floor(j/iFontWidth) = i\n"
"    //     mod(offset, iFontWidth) = mod(i*iFontWidth + j, iFontWidth) = j\n"
"    // - For texture coordinates (i,j) has to be rescaled to [0,1].\n"
"    // - Also we need to add an extra small offset to the texture coordinate\n"
"    //   in order to always \"hit\" the right pixel. Pixel width is\n"
"    //     1./iFontWidth.\n"
"    //   Half of it is in the center of the pixel.\n"
"    vec2 ind = (vec2(mod(off, iFontWidth), floor(off/iFontWidth))+.05)/iFontWidth;\n"
"    // Get 4 bytes of data from the texture\n"
"    vec4 block = texture(iFont, ind);\n"
"    // Select the appropriate word\n"
"    vec2 data = mix(block.rg, block.ba, hilo);\n"
"    // Convert bytes to unsigned short. The lower bytes operate on 255,\n"
"    // the higher bytes operate on 65280, which is the maximum range \n"
"    // of 65535 minus the lower 255.\n"
"    val = round(dot(vec2(255., 65280.), data));\n"
"}\n"
"\0";
const char *rfloat_source = "#version 130\n\n"
"\n"
"void rshort(in float off, out float val);\n"
"\n"
"void rfloat(in float off, out float val)\n"
"{\n"
"    // Convert the bytes to unsigned short as first step.\n"
"    float d;\n"
"    rshort(off, d);\n"
"    \n"
"    // Convert bytes to IEEE 754 float16. That is\n"
"    // 1 sign bit, 5 bit exponent, 11 bit mantissa.\n"
"    // Also it has a weird conversion rule that is not evident at all.\n"
"    float sign = floor(d/32768.),\n"
"        exponent = floor(d/1024.-sign*32.),\n"
"        significand = d-sign*32768.-exponent*1024.;\n"
"\n"
"    // Return full float16\n"
"    if(exponent == 0.)\n"
"    {\n"
"        val = mix(1., -1., sign) * 5.960464477539063e-08 * significand;\n"
"    }\n"
"    else\n"
"    {\n"
"        val = mix(1., -1., sign) * (1. + significand * 9.765625e-4) * pow(2.,exponent-15.);\n"
"    }\n"
"}\n"
"\0";
const char *dcircle_source = "#version 130\n\n"
"\n"
"void dcircle(in vec2 x, out float d)\n"
"{\n"
"    d = length(x)-1.0;\n"
"}\n"
"\0";
const char *drhomboid_source = "#version 130\n\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float dst);\n"
"\n"
"void drhomboid(in vec2 x, in vec2 b, in float tilt, out float dst)\n"
"{\n"
"    x.x -= tilt/2./b.y*x.y;\n"
"    dbox(x,b,dst);\n"
"}\n"
"\0";
const char *dcirclesegment_source = "#version 130\n\n"
"const float pi = acos(-1.);\n"
"void dcirclesegment(in vec2 x, in float R, in float p0, in float p1, out float d)\n"
"{\n"
"    float p = atan(x.y, x.x);\n"
"    vec2 philo = vec2(max(p0, p1), min(p0, p1));\n"
"    if((p < philo.x && p > philo.y) || (p+2.0*pi < philo.x && p+2.0*pi > philo.y) || (p-2.0*pi < philo.x && p-2.0*pi > philo.y))\n"
"        d = abs(length(x)-R);\n"
"    else d = min(\n"
"        length(x-vec2(cos(p0), sin(p0))),\n"
"        length(x-vec2(cos(p1), sin(p1)))\n"
"        );\n"
"}\n"
"\0";
const char *dglyph_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void rfloat(in float off, out float val);\n"
"void dbox(in vec2 x, in vec2 b, out float dst);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void dcircle(in vec2 x, out float d);\n"
"void dcirclesegment(in vec2 x, in float r, in float p0, in float p1, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst)\n"
"{\n"
"    float dis;\n"
"    dbox(x, 2.*size*c.xx, dis);\n"
"    if(dis > 0.)\n"
"    {\n"
"        dst = dis+.5*size;\n"
"        return;\n"
"    }\n"
"\n"
"    // Find glyph offset in glyph index\n"
"    float nglyphs, offset = 0;\n"
"    rfloat(1., nglyphs);\n"
"        \n"
"    for(float i=0.; i<nglyphs; i+=1.)\n"
"    {\n"
"        float ord;\n"
"        rfloat(2.+2.*i, ord);\n"
"        ord = floor(ord);\n"
"        \n"
"        if(ord == ordinal)\n"
"        {\n"
"            rfloat(2.+2.*i+1., offset);\n"
"            offset = floor(offset);\n"
"            break;\n"
"        }\n"
"    }\n"
"    \n"
"    if(offset == 0.) \n"
"    {\n"
"        dst = 1.;\n"
"        return;\n"
"    }\n"
"    \n"
"    // Get distance from glyph data\n"
"    float d = 1., da = 1.;\n"
"    \n"
"    // Lines\n"
"    float nlines;\n"
"    rfloat(offset, nlines);\n"
"    nlines = floor(nlines);\n"
"    offset += 1.;\n"
"    for(float i=0.; i<nlines; i+=1.)\n"
"    {\n"
"        float x1;\n"
"        rfloat(offset, x1);\n"
"        offset += 1.;\n"
"        float y1;\n"
"        rfloat(offset, y1);\n"
"        offset += 1.;\n"
"        float x2;\n"
"        rfloat(offset, x2);\n"
"        offset += 1.;\n"
"        float y2;\n"
"        rfloat(offset, y2);\n"
"        offset += 1.;\n"
"        dlinesegment(x, size*vec2(x1,y1), size*vec2(x2, y2), da);\n"
"        d = min(d,da);\n"
"    }\n"
"    \n"
"    stroke(d,.2*size,d);\n"
"    \n"
"    // Smooth lines\n"
"    float nsmoothlines, db = 1.;\n"
"    da = 1.;\n"
"    rfloat(offset, nsmoothlines);\n"
"    nsmoothlines = floor(nsmoothlines);\n"
"    offset += 1.;\n"
"    for(float i=0.; i<nsmoothlines; i+=1.)\n"
"    {\n"
"        float x1;\n"
"        rfloat(offset, x1);\n"
"        offset += 1.;\n"
"        float y1;\n"
"        rfloat(offset, y1);\n"
"        offset += 1.;\n"
"        float x2;\n"
"        rfloat(offset, x2);\n"
"        offset += 1.;\n"
"        float y2;\n"
"        rfloat(offset, y2);\n"
"        offset += 1.;\n"
"        dlinesegment(x, size*vec2(x1,y1), size*vec2(x2, y2), db);\n"
"        da = min(da, db);\n"
"    }\n"
"    stroke(da,.2*size, da);\n"
"    smoothmin(d,da,.1*size,d);\n"
"    \n"
"    \n"
"//     if(nlines+nsmoothlines== 0.)\n"
"//         dst = dis;\n"
"//     else dst = d;\n"
"    dst = d;\n"
"}\n"
"\0";
const char *dstring_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void rfloat(in float off, out float val);\n"
"void dbox(in vec2 x, in vec2 b, out float dst);\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst);\n"
"\n"
"void dstring(in vec2 x, in float ordinal, in float size, out float dst)\n"
"{\n"
"    // Get string database offset\n"
"    float stroff0;\n"
"    rfloat(0., stroff0);\n"
"    stroff0 = floor(stroff0);\n"
"    \n"
"    // Return 1 if wrong ordinal is supplied\n"
"    float nstrings;\n"
"    rfloat(stroff0, nstrings);\n"
"    nstrings = floor(nstrings);\n"
"    if(ordinal >= nstrings)\n"
"    {\n"
"        dst = 1.;\n"
"        return;\n"
"    }\n"
"    \n"
"    // Get offset and length of string from string database index\n"
"    float stroff;\n"
"    rfloat(stroff0+1.+2.*ordinal, stroff);\n"
"    stroff = floor(stroff);\n"
"    float len;\n"
"    rfloat(stroff0+2.+2.*ordinal, len);\n"
"    len = floor(len);\n"
"    \n"
"    // Draw glyphs\n"
"    vec2 dx = mod(x-size, 2.*size)-size, \n"
"        ind = ceil((x-dx+size)/2./size);\n"
"    \n"
"    // Bounding box\n"
"    float bound;\n"
"    dbox(x-size*(len-3.)*c.xy, vec2(size*len, 1.*size), bound);\n"
"    if(bound > 0.)\n"
"    {\n"
"        dst = bound+.5*size;\n"
"        return;\n"
"    }\n"
"    \n"
"    float da;\n"
"    rfloat(stroff+ind.x, da);\n"
"    da = floor(da);\n"
"    dglyph(dx, da, .7*size, dst);\n"
"}\n"
"\0";
const char *dfloat_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst);\n"
"\n"
"void dfloat(in vec2 x, in float num, in float size, out float dst)\n"
"{\n"
"    float d = 1., index = 0.;\n"
"    \n"
"    // Determine sign and output it if present\n"
"    float sign = sign(num), exp = 0.;\n"
"    if(sign<0.)\n"
"    {\n"
"        float da;\n"
"        dglyph(x, 45., .7*size, da);\n"
"        d = min(d, da);\n"
"        index += 1.;\n"
"        num *= -1.;\n"
"    }\n"
"    \n"
"    // The first power of ten that floors num to anything not zero is the exponent\n"
"    for(exp = -15.; exp < 15.; exp += 1.)\n"
"        if(floor(num*pow(10.,exp)) != 0.)\n"
"            break;\n"
"    exp *= -1.;\n"
"    // Determine the significand and output it\n"
"    for(float i = exp; i >= max(exp-5.,-33); i -= 1.)\n"
"    {\n"
"        float po = pow(10.,i);\n"
"        float ca = floor(num/po);\n"
"        num -= ca*po;\n"
"        \n"
"        float da;\n"
"        dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"        d = min(d, da);\n"
"        index += 1.;\n"
"        if(i == exp) // decimal point\n"
"        {\n"
"            dglyph(x-2.*index*size*c.xy, 46., .7*size, da);\n"
"            d = min(d, da);\n"
"            index += 1.;\n"
"        }\n"
"    }\n"
"    \n"
"    // Output the exponent\n"
"    float db;\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 101., .7*size, db);\n"
"    d = min(d, db);\n"
"    index += 1.;\n"
"    if(exp < 0.) // Sign\n"
"    {\n"
"        dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 45., .7*size,db);\n"
"        d = min(d, db);\n"
"        index += 1.;\n"
"        exp *= -1.;\n"
"    }\n"
"    float ca = floor(exp/10.);\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, db);\n"
"    d = min(d, db);\n"
"    index += 1.;\n"
"    ca = floor(exp-10.*ca);\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, db);\n"
"    d = min(d, db);\n"
"    index += 1.;\n"
"    \n"
"    dst = d;\n"
"}\n"
"\0";
const char *dint_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst);\n"
"\n"
"void dint(in vec2 x, in float num, in float size, in float ndigits, out float dst)\n"
"{\n"
"    float d = 1., index = 0.;\n"
"    \n"
"    if(num == 0.)\n"
"    {\n"
"        index = ndigits;\n"
"        dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48., .7*size, dst);\n"
"        return;\n"
"    } \n"
"    \n"
"    // Determine sign and output it if present\n"
"    float sign = sign(num), exp = 0.;\n"
"    if(sign<0.)\n"
"    {\n"
"        float da;\n"
"        dglyph(x, 45., .7*size, da);\n"
"        d = min(d, da);\n"
"        index += 1.;\n"
"        num *= -1.;\n"
"    }\n"
"    \n"
"    // The first power of ten that floors num to anything not zero is the exponent\n"
"    for(exp = -15.; exp < 15.; exp += 1.)\n"
"        if(floor(num*pow(10.,exp)) != 0.)\n"
"            break;\n"
"    exp *= -1.;\n"
"    \n"
"    int hit = 0;\n"
"    \n"
"    // Determine the significand and output it\n"
"    for(float i = ndigits; i >= 0.; i -= 1.)\n"
"    {\n"
"        float po = pow(10.,i);\n"
"        float ca = floor(num/po);\n"
"        if(ca == 0.) \n"
"        {\n"
"            if(hit == 0)\n"
"            {\n"
"                index += 1.;\n"
"                continue;\n"
"            }\n"
"            \n"
"        }\n"
"        else hit = 1;\n"
"        num -= ca*po;\n"
"        \n"
"        float da;\n"
"        dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"        d = min(d, da);\n"
"        index += 1.;\n"
"    }\n"
"    \n"
"    \n"
"    \n"
"    dst = d;\n"
"}\n"
"\0";
const char *dtime_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst);\n"
"\n"
"// Time in format: 00:00\n"
"void dtime(in vec2 x, in float num, in float size, out float dst)\n"
"{\n"
"    float d = 1., index = 0.;\n"
"    \n"
"    num = floor(num);\n"
"\n"
"    // 10 minutes\n"
"    float ca = floor(num/600.), da = 1.;\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"    d = min(d, da);\n"
"    index += 1.;\n"
"    num -= ca*600.;\n"
"\n"
"    // minutes\n"
"    ca = floor(num/60.);\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"    d = min(d, da);\n"
"    index += 1.;\n"
"    num -= ca*60.;\n"
"\n"
"    // :\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 58., .7*size, da);\n"
"    d = min(d, da);\n"
"    index += 1.;\n"
"    \n"
"    // 10 seconds\n"
"    ca = floor(num/10.);\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"    d = min(d, da);\n"
"    index += 1.;\n"
"    num -= ca*10.;\n"
"    \n"
"    // 1 seconds\n"
"    ca = floor(num/1.);\n"
"    dglyph(x+.7*size*c.xy-2.*index*size*c.xy, 48.+ca, .7*size, da);\n"
"    d = min(d, da);\n"
"    \n"
"    dst = d;\n"
"}\n"
"\0";
const char *addwindow_source = "#version 130\n\n"
"\n"
"uniform vec2 iResolution;\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"\n"
"#define sm(d) smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d)\n"
"\n"
"void addwindow(in vec2 uv, inout vec3 col, in vec2 dimensions)\n"
"{\n"
"    float d = 1.;\n"
"    \n"
"    // Background loading bar window\n"
"    dbox(uv, dimensions, d);\n"
"    vec3 gcol = length(col)/sqrt(3.)*c.xxx;\n"
"    const vec3 window_raw = vec3(0.08,0.07,0.16);\n"
"    vec3 window_background = mix(mix(col,window_raw,.2), mix(gcol,window_raw,.8), clamp((.5-uv.y/dimensions.y*.5),0.,1.));\n"
"    \n"
"    // Shadow\n"
"    col = mix(col, .1*gcol, sm(d/8.));\n"
"    // Window\n"
"    col = mix(col, window_background, sm(d));\n"
"    \n"
"    // White border on loading bar window\n"
"    d = abs(d-.002)-.002;\n"
"    d = mix(d, 1., step(abs(uv.y),dimensions.y-.01));\n"
"    col = mix(col, c.xxx, sm(d));\n"
"    \n"
"    // X box\n"
"    dbox(uv-(dimensions-.04*c.xx), .015*c.xx, d);\n"
"    col = mix(col, c.xxx, sm(d+.005));\n"
"    stroke(d, .001, d);\n"
"    col = mix(col, c.xxx, sm(d));\n"
"    \n"
"    // Actual x\n"
"    dlinesegment(uv,dimensions-.05*c.xx,dimensions-.03*c.xx,d);\n"
"    float da;\n"
"    dlinesegment(uv,dimensions-vec2(.05,.03),dimensions-vec2(.03,.05),da);\n"
"    d = min(d,da);\n"
"    stroke(d,.002, d);\n"
"    col = mix(col, c.yyy, sm(d));\n"
"}\n"
"\0";
const char *ddeadline_source = "#version 130\n\n"
"\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"\n"
"const int npts = 368;\n"
"const float path[npts] = float[npts](0.114,-0.123,0.102,-0.137,0.102,-0.137,0.040,-0.137,0.040,-0.137,-0.013,-0.078,-0.013,-0.078,-0.064,-0.137,-0.064,-0.137,-0.153,-0.137,-0.153,-0.137,-0.165,-0.123,-0.165,-0.123,-0.176,-0.137,-0.176,-0.137,-0.380,-0.137,-0.380,-0.137,-0.500,0.002,-0.500,0.002,-0.412,0.104,-0.412,0.104,-0.393,0.104,-0.393,0.104,-0.480,0.002,-0.480,0.002,-0.467,0.002,-0.467,0.002,-0.380,0.104,-0.380,0.104,-0.297,0.104,-0.297,0.104,-0.253,0.054,-0.253,0.054,-0.238,0.073,-0.238,0.073,-0.259,0.073,-0.259,0.073,-0.288,0.104,-0.288,0.104,0.030,0.104,0.030,0.104,-0.039,0.023,-0.039,0.023,-0.196,0.023,-0.196,0.023,-0.205,0.033,-0.205,0.033,-0.228,0.002,-0.228,0.002,-0.044,0.002,-0.044,0.002,0.042,0.104,0.042,0.104,0.067,0.104,0.067,0.104,-0.020,0.002,-0.020,0.002,-0.011,0.002,-0.011,0.002,0.077,0.104,0.077,0.104,0.090,0.104,0.090,0.104,0.057,0.145,0.057,0.145,0.123,0.145,0.123,0.145,0.156,0.104,0.156,0.104,0.357,0.105,0.357,0.105,0.332,0.072,0.332,0.072,0.260,0.072,0.260,0.072,0.301,0.023,0.301,0.023,0.404,0.145,0.404,0.145,0.470,0.145,0.470,0.145,0.349,0.001,0.349,0.001,0.255,0.001,0.255,0.001,0.195,0.072,0.195,0.072,0.185,0.072,0.185,0.072,0.251,-0.009,0.251,-0.009,0.352,-0.009,0.352,-0.009,0.481,0.145,0.481,0.145,0.500,0.145,0.500,0.145,0.376,-0.009,0.376,-0.009,0.442,-0.086,0.442,-0.086,0.143,-0.086,0.143,-0.086,0.127,-0.107,0.127,-0.107,0.396,-0.107,0.396,-0.107,0.428,-0.145,0.428,-0.145,0.133,-0.145,0.133,-0.145,0.114,-0.123,-0.155,-0.050,-0.131,-0.050,-0.131,-0.050,-0.094,-0.093,-0.094,-0.093,-0.047,-0.039,-0.047,-0.039,-0.144,-0.038,-0.144,-0.038,-0.240,-0.037,-0.240,-0.037,-0.252,-0.025,-0.252,-0.025,-0.263,-0.037,-0.263,-0.037,-0.398,-0.039,-0.398,-0.039,-0.340,-0.107,-0.340,-0.107,-0.180,-0.107,-0.180,-0.107,-0.231,-0.050,-0.231,-0.050,-0.164,-0.050,-0.164,-0.050,-0.112,-0.116,-0.112,-0.116,-0.107,-0.109,-0.107,-0.109,-0.155,-0.050,0.125,-0.038,0.032,-0.036,0.032,-0.036,0.065,0.003,0.065,0.003,0.175,0.003,0.175,0.003,0.115,0.072,0.115,0.072,0.022,-0.037,0.022,-0.037,0.073,-0.098,0.073,-0.098,0.125,-0.038,0.350,-0.056,0.336,-0.037,0.336,-0.037,0.210,-0.037,0.210,-0.037,0.200,-0.024,0.200,-0.024,0.172,-0.056,0.172,-0.056,0.350,-0.056,-0.281,0.023,-0.299,0.023,-0.299,0.023,-0.341,0.071,-0.341,0.071,-0.401,0.002,-0.401,0.002,-0.297,0.002,-0.297,0.002,-0.281,0.023,-0.063,0.073,-0.172,0.073,-0.172,0.073,-0.186,0.055,-0.186,0.055,-0.076,0.055,-0.076,0.055,-0.063,0.073);\n"
"\n"
"void ddeadline(in vec2 x, out float ret)\n"
"{\n"
"    ret = 1.;\n"
"    float da;\n"
"\n"
"    float n = 0.;\n"
"    for(int i=0; i<npts/4; ++i)\n"
"    {\n"
"        vec2 ptsi = vec2(path[4*i], path[4*i+1]),\n"
"            ptsip1 = vec2(path[4*i+2], path[4*i+3]),\n"
"            k = x-ptsi, \n"
"            d = ptsip1-ptsi;\n"
"        \n"
"        float beta = k.x/d.x,\n"
"            alpha = d.y*k.x/d.x-k.y;\n"
"        \n"
"        n += step(.0, beta)*step(beta, 1.)*step(0., alpha);\n"
"        dlinesegment(x, ptsi, ptsip1, da);\n"
"        ret = min(ret, da);\n"
"    }\n"
"    \n"
"    ret = mix(ret, -ret, mod(n, 2.));\n"
"}\n"
"\0";
const char *dpolygon_source = "#version 130\n\n"
"// compute distance to regular polygon\n"
"const float pi = acos(-1.);\n"
"void dpolygon(in vec2 x, in float N, out float d)\n"
"{\n"
"    d = 2.0*pi/N;\n"
"    float t = mod(acos(x.x/length(x)), d)-0.5*d;\n"
"    d = -0.5+length(x)*cos(t)/cos(0.5*d);\n"
"}\n"
"\0";
const char *dspacepigs_source = "#version 130\n\n"
"\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"void dcircle(in vec2 x, out float d);\n"
"\n"
"void dear(in vec2 x, out float d)\n"
"{\n"
"    d = abs(2.*x.y)\n"
"        -.95+smoothstep(0.,.5,clamp(abs(x.x),0.,1.))\n"
"        -.5*min(-abs(x.x),.01);\n"
"}\n"
"\n"
"void dspacepigs(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da, d0;\n"
"    \n"
"    // Head\n"
"    dcircle(2.5*x,d0);\n"
"    d0 /= 2.5;\n"
"    \n"
"    // Ears\n"
"    dear(vec2(2.,5.)*x-vec2(.8,1.3), da);\n"
"    d0 = min(d0,da/10.);\n"
"    dear(vec2(2.,5.)*x+vec2(.8,-1.3), da);\n"
"    d0 = min(d0,da/10.);\n"
"    \n"
"    // Nose\n"
"    dcircle(6.*x-vec2(0.,-.5),da);\n"
"    d0 = max(d0,-da/6.);\n"
"    dcircle(24.*x-vec2(-1.5,-2.),da);\n"
"    d0 = min(d0,da/24.);\n"
"    dcircle(24.*x-vec2(1.5,-2.),da);\n"
"    d0 = min(d0,da/24.);\n"
"    \n"
"    // Eyes\n"
"    dcircle(16.*x-vec2(-3.5,2.5),da);\n"
"    d0 = max(d0,-da/16.);\n"
"    dcircle(16.*x-vec2(3.5,2.5),da);\n"
"    d0 = max(d0,-da/16.);\n"
"    dcircle(24.*x-vec2(-5.,3.5),da);\n"
"    d0 = min(d0,da/24.);\n"
"    dcircle(24.*x-vec2(5.,3.5),da);\n"
"    d0 = min(d0,da/24.);\n"
"    \n"
"    d = max(d, -d0);\n"
"}\n"
"\0";
const char *analytical_box_source = "#version 130\n\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void analytical_box(in vec3 o, in vec3 dir, in vec3 size, out float d)\n"
"{\n"
"    vec3 tlo = min((size-o)/dir,(-size-o)/dir); // Select 3 visible planes\n"
"    vec2 abxlo = abs(o.yz + tlo.x*dir.yz),\n"
"        abylo = abs(o.xz + tlo.y*dir.xz),\n"
"        abzlo = abs(o.xy + tlo.z*dir.xy);\n"
"    vec4 dn = 100.*c.xyyy;\n"
"    \n"
"    dn = mix(dn, vec4(tlo.x,c.xyy), float(all(lessThan(abxlo,size.yz)))*step(tlo.x,dn.x));\n"
"    dn = mix(dn, vec4(tlo.y,c.yxy), float(all(lessThan(abylo,size.xz)))*step(tlo.y,dn.x));\n"
"    dn = mix(dn, vec4(tlo.z,c.yyx), float(all(lessThan(abzlo,size.xy)))*step(tlo.z,dn.x));\n"
"\n"
"    d = dn.r;\n"
"}\n"
"\0";
const char *hash33_source = "// Creative Commons Attribution-ShareAlike 4.0 International Public License\n"
"// Created by David Hoskins.\n"
"// See https://www.shadertoy.com/view/4djSRW\n"
"void hash33(in vec3 p3, out vec3 d)\n"
"{\n"
"	p3 = fract(p3 * vec3(.1031, .1030, .0973));\n"
"    p3 += dot(p3, p3.yxz+33.33);\n"
"    d = fract((p3.xxy + p3.yxx)*p3.zyx);\n"
"}\n"
"\0";
const char *dvoronoi3_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void hash33(in vec3 p3, out vec3 d);\n"
"\n"
"void dist3(in vec3 a, in vec3 b, out float d)\n"
"{\n"
"    d = length(b-a);\n"
"}\n"
"\n"
"void nearest_controlpoint3(in vec3 x, out vec3 p)\n"
"{\n"
"    float dmin = 1.e5, \n"
"        d;\n"
"    vec3 dp,\n"
"        y = floor(x);\n"
"    \n"
"    for(float i = -1.; i <= 1.; i += 1.)\n"
"        for(float j = -1.; j <= 1.; j += 1.)\n"
"        {\n"
"            for(float k = -1.; k <= 1.; k += 1.)\n"
"            {\n"
"                hash33(y+vec3(i,j,k), dp);\n"
"                dp += y+vec3(i,j,k);\n"
"                dist3(x, dp, d);\n"
"                if(d<dmin)\n"
"                {\n"
"                    dmin = d;\n"
"                    p = dp;\n"
"                }\n"
"            }\n"
"        }\n"
"}\n"
"\n"
"void dvoronoi3(in vec3 x, out float d, out vec3 p, out float control_distance)\n"
"{\n"
"    d = 1.e4;\n"
"    vec3 y,\n"
"        dp;\n"
"    \n"
"    nearest_controlpoint3(x, p);\n"
"    y = floor(p);\n"
"    \n"
"    control_distance = 1.e4;\n"
"    \n"
"    for(float i = -2.; i <= 2.; i += 1.)\n"
"        for(float j = -2.; j <= 2.; j += 1.)\n"
"        {\n"
"            for(float k = -1.; k <= 1.; k += 1.)\n"
"            {\n"
"                if(i==0. && j==0. && k == 0.) continue;\n"
"                hash33(y+vec3(i,j,k), dp);\n"
"                dp += y+vec3(i,j,k);\n"
"                vec3 o = p - dp;\n"
"                float l = length(o);\n"
"                d = min(d,abs(.5*l-dot(x-dp,o)/l));\n"
"                control_distance = min(control_distance,.5*l);\n"
"            }\n"
"        }\n"
"}\n"
"\0";
const char *dsmoothvoronoi3_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void hash33(in vec3 p3, out vec3 d);\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"\n"
"void dist3_s(in vec3 a, in vec3 b, out float d)\n"
"{\n"
"    d = length(b-a);\n"
"}\n"
"\n"
"void nearest_controlpoint3_s(in vec3 x, out vec3 p)\n"
"{\n"
"    float dmin = 1.e5, \n"
"        d;\n"
"    vec3 dp,\n"
"        y = floor(x);\n"
"    \n"
"    for(float i = -1.; i <= 1.; i += 1.)\n"
"        for(float j = -1.; j <= 1.; j += 1.)\n"
"        {\n"
"            for(float k = -1.; k <= 1.; k += 1.)\n"
"            {\n"
"                hash33(y+vec3(i,j,k), dp);\n"
"                dp += y+vec3(i,j,k);\n"
"                dist3_s(x, dp, d);\n"
"                if(d<dmin)\n"
"                {\n"
"                    dmin = d;\n"
"                    p = dp;\n"
"                }\n"
"            }\n"
"        }\n"
"}\n"
"\n"
"void dsmoothvoronoi3(in vec3 x, out float d, out vec3 p, out float control_distance)\n"
"{\n"
"    d = 1.e4;\n"
"    vec3 y,\n"
"        dp;\n"
"    \n"
"    nearest_controlpoint3_s(x, p);\n"
"    y = floor(p);\n"
"    \n"
"    control_distance = 1.e4;\n"
"    \n"
"    for(float i = -2.; i <= 2.; i += 1.)\n"
"        for(float j = -2.; j <= 2.; j += 1.)\n"
"        {\n"
"            for(float k = -1.; k <= 1.; k += 1.)\n"
"            {\n"
"                if(i==0. && j==0. && k == 0.) continue;\n"
"                hash33(y+vec3(i,j,k), dp);\n"
"                dp += y+vec3(i,j,k);\n"
"                vec3 o = p - dp;\n"
"                float l = length(o);\n"
"//                 d = min(d,abs(.5*l-dot(x-dp,o)/l));\n"
"                smoothmin(d,abs(.5*l-dot(x-dp,o)/l), .15, d);\n"
"//                 control_distance = min(control_distance,.5*l);\n"
"                smoothmin(control_distance, .5*l, .15, control_distance);\n"
"            }\n"
"        }\n"
"}\n"
"\0";
const char *dstar_source = "#version 130\n\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"void dstar(in vec2 x, in float N, in vec2 R, out float dst)\n"
"{\n"
"    float d = pi/N,\n"
"        p0 = acos(x.x/length(x)),\n"
"        p = mod(p0, d),\n"
"        i = mod(round((p-p0)/d),2.);\n"
"    x = length(x)*vec2(cos(p),sin(p));\n"
"    vec2 a = mix(R,R.yx,i),\n"
"    	p1 = a.x*c.xy,\n"
"        ff = a.y*vec2(cos(d),sin(d))-p1;\n"
"   	ff = ff.yx*c.zx;\n"
"    dst = dot(x-p1,ff)/length(ff);\n"
"}\n"
"\0";
const char *smoothmax_source = "#version 130\n\n"
"\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"\n"
"void smoothmax(in float a, in float b, in float k, out float res)\n"
"{\n"
"    smoothmin(a,b,k,res);\n"
"    res = a + b - res;\n"
"}\n"
"\0";
const char *dstar3_source = "#version 130\n\n"
"\n"
"void dstar(in vec2 x, in float N, in vec2 R, out float dst);\n"
"void smoothmax(in float a, in float b, in float k, out float res);\n"
"\n"
"void dstar3(in vec3 x, in float N, in vec2 R, out float dst)\n"
"{\n"
"    float d;\n"
"    \n"
"    dstar(x.xy, N, R, dst);\n"
"    dstar(x.yz, N, R, d);\n"
"    smoothmax(-d,-dst,.15,dst);\n"
"    dstar(x.zx, N, R, d);\n"
"    smoothmax(-d,dst,.15,dst);\n"
"}\n"
"\0";
const char *dhexagonpattern_source = "// Distance to hexagon pattern\n"
"void dhexagonpattern(in vec2 p, out float d, out vec2 ind) \n"
"{\n"
"    vec2 q = vec2( p.x*1.2, p.y + p.x*0.6 );\n"
"    \n"
"    vec2 pi = floor(q);\n"
"    vec2 pf = fract(q);\n"
"\n"
"    float v = mod(pi.x + pi.y, 3.0);\n"
"\n"
"    float ca = step(1.,v);\n"
"    float cb = step(2.,v);\n"
"    vec2  ma = step(pf.xy,pf.yx);\n"
"    \n"
"    d = dot( ma, 1.0-pf.yx + ca*(pf.x+pf.y-1.0) + cb*(pf.yx-2.0*pf.xy) );\n"
"    ind = pi + ca - cb*ma;\n"
"    ind = vec2(ind.x/1.2, ind.y);\n"
"    ind = vec2(ind.x, ind.y-ind.x*.6);\n"
"}\n"
"\0";
const char *dmercury_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"\n"
"void dmercury(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da;\n"
"\n"
"    x += .1*c.yx;\n"
"\n"
"    // Upper part\n"
"    dbox(x-.35*c.yx,vec2(.4,.35), da);\n"
"    d = max(d, -da);\n"
"    dbox(x-.7*c.yx, vec2(.2,.2), da);\n"
"    d = min(d,da);\n"
"    dbox(x-.25*c.yx,vec2(.2,.05),da);\n"
"    d = min(d,da);\n"
"    \n"
"    // Lower part\n"
"    dbox(x+.2*c.yx,vec2(.1,.4),da);\n"
"    d = max(d, -da);\n"
"    dbox(x+.2*c.yx, vec2(.4,.1),da);\n"
"    d = max(d, -da);\n"
"}\n"
"\0";
const char *dtriangle_source = "// Adapted from iq, https://www.shadertoy.com/view/XsXSz4\n"
"void dtriangle(in vec2 p, in vec2 p0, in vec2 p1, in vec2 p2, out float dst)\n"
"{\n"
"	vec2 e0 = p1 - p0;\n"
"	vec2 e1 = p2 - p1;\n"
"	vec2 e2 = p0 - p2;\n"
"\n"
"	vec2 v0 = p - p0;\n"
"	vec2 v1 = p - p1;\n"
"	vec2 v2 = p - p2;\n"
"\n"
"	vec2 pq0 = v0 - e0*clamp( dot(v0,e0)/dot(e0,e0), 0.0, 1.0 );\n"
"	vec2 pq1 = v1 - e1*clamp( dot(v1,e1)/dot(e1,e1), 0.0, 1.0 );\n"
"	vec2 pq2 = v2 - e2*clamp( dot(v2,e2)/dot(e2,e2), 0.0, 1.0 );\n"
"    \n"
"    float s = sign( e0.x*e2.y - e0.y*e2.x );\n"
"    vec2 d = min( min( vec2( dot( pq0, pq0 ), s*(v0.x*e0.y-v0.y*e0.x) ),\n"
"                       vec2( dot( pq1, pq1 ), s*(v1.x*e1.y-v1.y*e1.x) )),\n"
"                       vec2( dot( pq2, pq2 ), s*(v2.x*e2.y-v2.y*e2.x) ));\n"
"\n"
"	dst = -sqrt(d.x)*sign(d.y);\n"
"}\n"
"\0";
const char *rot_source = "#version 130\n\n"
"void rot(in float phi, out mat2 m)\n"
"{\n"
"    vec2 cs = vec2(cos(phi), sin(phi));\n"
"    m = mat2(cs.x, -cs.y, cs.y, cs.x);\n"
"}\n"
"\0";
const char *dschnappsgirls_source = "#version 130\n\n"
"\n"
"void dtriangle(in vec2 x, in vec2 p0, in vec2 p1, in vec2 p2, out float d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void dcircle(in vec2 x, out float d);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"\n"
"void dschnappsgirls(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da, d0;\n"
"    \n"
"    // Dress\n"
"    dtriangle(x, vec2(-.1,-.3), vec2(.5,-.3), vec2(.2, .6), d0);\n"
"    dlinesegment(x, vec2(-.1,.325), vec2(.5,.325), da);\n"
"    stroke(da,.06,da);\n"
"    d0 = max(d0,-da);\n"
"    \n"
"    // Head\n"
"    dcircle(7.*(x-vec2(.2,.5)), da);\n"
"    d0 = max(d0, -da+.5);\n"
"    d0 = min(d0, da/7.);\n"
"    \n"
"    // Legs\n"
"    dlinesegment(x, vec2(.125,-.3), vec2(.125,-.6), da);\n"
"    stroke(da, .06, da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x, vec2(.275,-.3), vec2(.275,-.6), da);\n"
"    stroke(da, .06, da);\n"
"    d0 = min(d0, da);\n"
"    \n"
"    // Shoulders\n"
"    dlinesegment(x, vec2(0.05,.25), vec2(.35,.25), da);\n"
"    stroke(da, .085, da);\n"
"    d0 = min(d0, da);\n"
"    \n"
"    // Arms\n"
"    dlinesegment(x, vec2(.385,.25), vec2(.5, -.1), da);\n"
"    stroke(da, .055, da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x, vec2(.017,.25), vec2(-.1, -.1), da);\n"
"    stroke(da, .055, da);\n"
"    d0 = min(d0, da);\n"
"    \n"
"    // Glass\n"
"    dtriangle(x, vec2(-.6,.3), vec2(-.4,.1), vec2(-.2,.3), da);\n"
"    stroke(da, .0125, da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x, vec2(-.4,.15), vec2(-.4,-.1), da);\n"
"    stroke(da, .0125, da);\n"
"    d0 = min(d0, da);\n"
"    dtriangle(x, vec2(-.5,-.15), vec2(-.3,-.15), vec2(-.4,-.1), da);\n"
"    d0 = min(d0, da);\n"
"    \n"
"    // Liquid\n"
"    dtriangle(x, vec2(-.55,.25), vec2(-.4,.1), vec2(-.25,.25), da);\n"
"    d0 = min(d0, da);\n"
"    \n"
"    // Salad\n"
"    dlinesegment(x, vec2(-.4,.1), vec2(-.2,.5), da);\n"
"    stroke(da, .01, da);\n"
"    d0 = min(d0, da);\n"
"    dcircle(24.*(x-vec2(-.3,.3)), da);\n"
"    d0 = min(d0, da/24.);\n"
"    dcircle(24.*(x-vec2(-.25,.4)), da);\n"
"    d0 = min(d0, da/24.);\n"
"    \n"
"    d = max(d, -d0);\n"
"}\n"
"\0";
const char *dhaujobb_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"const float pi = acos(-1.);\n"
"\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"void rot(in float phi, out mat2 m);\n"
"void dcircle(in vec2 x, out float d);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"\n"
"void dhaujobb(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da, d0;\n"
"    mat2 m;\n"
"	rot(.3,m);\n"
"    x = 1.1*x*m;\n"
"    x.x *= 1.1;\n"
"        \n"
"    x += vec2(-.05,.2);\n"
"    \n"
"    // Left leg\n"
"    dbox(x+.35*c.xx,vec2(.1,.05),d0);\n"
"    dbox(x+vec2(.3,.25),vec2(.05,.15),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(x+vec2(.2,.15),vec2(.1,.05),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(x+vec2(.15,.05),vec2(.05,.15),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    // Right leg\n"
"    dbox(x-vec2(.65,.35),vec2(.05,.15),da);\n"
"    d0 = min(d0,da);\n"
"\n"
"    // Torso\n"
"    rot(.2, m);\n"
"    dbox(m*(x-vec2(.25,.15)),vec2(.45,.05),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(m*(x-vec2(-.15,.35)),vec2(.45,.05),da);\n"
"    d0 = min(d0,da);\n"
"    rot(pi/8.,m);\n"
"    dbox(m*(x-vec2(.0,.25)),vec2(.1,.15),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    // Penis\n"
"    dbox(m*(x-vec2(.1,-.0)),vec2(.025,.1),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    // Left hand\n"
"    rot(.3,m);\n"
"    dbox(m*(x-vec2(.235,.535)),vec2(.035,.15),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(m*(x-vec2(.225,.7)),vec2(.075,.025),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    // Right hand\n"
"    rot(-.2,m);\n"
"    dbox(m*(x+vec2(.585,-.2)),vec2(.0375,.1),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    // Head\n"
"    dcircle(6.*(x-vec2(-.15,.58)),da);\n"
"    d0 = min(d0,da/6.);\n"
"    \n"
"    d0 -= .05*(abs(x.x)+abs(x.y)-.2);\n"
"    d = max(d,-d0);\n"
"}\n"
"\0";
const char *dkewlers_source = "#version 130\n\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"\n"
"void dkewlers(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da, d0;\n"
"    \n"
"    x *= 1.2;\n"
"    \n"
"    dbox(x-vec2(0.,-.3),vec2(.6,.1),d0);\n"
"    dbox(x-vec2(-.5,-.0),vec2(.1,.25),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(x-vec2(-.5+1./3.,.25),vec2(.1,.5),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(x-vec2(-.5+2./3.,-.0),vec2(.1,.25),da);\n"
"    d0 = min(d0,da);\n"
"    dbox(x-vec2(.5,-.0),vec2(.1,.25),da);\n"
"    d0 = min(d0,da);\n"
"    \n"
"    d = max(d, -d0);\n"
"}\n"
"\0";
const char *dfarbrausch_source = "#version 130\n\n"
"\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"\n"
"void dfarbrausch(in vec2 x, out float d)\n"
"{\n"
"    dpolygon(.5*x,6.0,d);\n"
"    float da, d0;\n"
"    \n"
"    x += vec2(.1,0.);\n"
"    x *= 1.2;\n"
"    \n"
"    dlinesegment(x,vec2(-.65,.05),vec2(-.5,.05),d0);\n"
"    dlinesegment(x,vec2(-.5,.05),vec2(-.2,-.49),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(-.2,-.49),vec2(-.0,-.49),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(-.0,-.49),vec2(-.27,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(-.07,0.),vec2(-.27,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.2,-.49),vec2(-.07,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.4,-.49),vec2(.13,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.4,-.49),vec2(.2,-.49),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.33,0.),vec2(.13,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.33,0.),vec2(.51,-.33),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.6,-.15),vec2(.51,-.33),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.53,0.),vec2(.6,-.15),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.7,0.),vec2(.53,.0),da);\n"
"    d0 = min(d0, da);\n"
"    dlinesegment(x,vec2(.7,0.),vec2(.68,-.04),da);\n"
"    d0 = min(d0, da);\n"
"    dpolygon(5.*(x+vec2(.3,.65)),6.,da);\n"
"    d0 = min(d0, da/5.);\n"
"    dpolygon(5.*(x+vec2(-.5,.65)),6.,da);\n"
"    d0 = min(d0, da/5.);\n"
"    \n"
"    stroke(d0,.035, d0);\n"
"    d = max(d, -d0);\n"
"}\n"
"\0";
const char *d5711_source = "#version 130\n\n"
"\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"\n"
"const int npts = 208;\n"
"const float path[npts] = float[npts](-0.500,0.145,-0.500,-0.029,-0.500,-0.029,-0.353,-0.029,-0.353,-0.029,-0.353,-0.087,-0.353,-0.087,-0.500,-0.087,-0.500,-0.087,-0.500,-0.145,-0.500,-0.145,-0.280,-0.145,-0.280,-0.145,-0.280,0.029,-0.280,0.029,-0.427,0.029,-0.427,0.029,-0.427,0.087,-0.427,0.087,-0.280,0.087,-0.280,0.087,-0.280,0.145,-0.280,0.145,-0.500,0.145,-0.500,0.145,-0.500,0.145,-0.240,0.145,-0.240,0.087,-0.240,0.087,-0.093,0.087,-0.093,0.087,-0.093,0.029,-0.093,0.029,-0.020,0.029,-0.020,0.029,-0.020,0.145,-0.020,0.145,-0.240,0.145,-0.093,0.029,-0.167,0.029,-0.167,0.029,-0.167,-0.087,-0.167,-0.087,-0.093,-0.087,-0.093,-0.087,-0.093,0.029,-0.093,0.029,-0.093,0.029,-0.167,-0.087,-0.240,-0.087,-0.240,-0.087,-0.240,-0.145,-0.240,-0.145,-0.167,-0.145,-0.167,-0.145,-0.167,-0.087,0.093,0.145,0.093,0.087,0.093,0.087,0.020,0.087,0.020,0.087,0.020,0.029,0.020,0.029,0.093,0.029,0.093,0.029,0.093,-0.087,0.093,-0.087,0.020,-0.087,0.020,-0.087,0.020,-0.145,0.020,-0.145,0.240,-0.145,0.240,-0.145,0.240,-0.087,0.240,-0.087,0.167,-0.087,0.167,-0.087,0.167,0.145,0.167,0.145,0.093,0.145,0.353,0.145,0.353,0.087,0.353,0.087,0.280,0.087,0.280,0.087,0.280,0.029,0.280,0.029,0.353,0.029,0.353,0.029,0.353,-0.087,0.353,-0.087,0.280,-0.087,0.280,-0.087,0.280,-0.145,0.280,-0.145,0.500,-0.145,0.500,-0.145,0.500,-0.087,0.500,-0.087,0.427,-0.087,0.427,-0.087,0.427,0.145,0.427,0.145,0.353,0.145);\n"
"void d5711(in vec2 x, out float ret)\n"
"{\n"
"    float d;\n"
"    dpolygon(.5*x,6.0,d);\n"
"    \n"
"    x *= .7;\n"
"    ret = 1.;\n"
"    float da;\n"
"\n"
"    float n = 0.;\n"
"    for(int i=0; i<npts/4; ++i)\n"
"    {\n"
"        vec2 ptsi = vec2(path[4*i], path[4*i+1]),\n"
"            ptsip1 = vec2(path[4*i+2], path[4*i+3]),\n"
"            k = x-ptsi, \n"
"            d = ptsip1-ptsi;\n"
"        \n"
"        float beta = k.x/d.x,\n"
"            alpha = d.y*k.x/d.x-k.y;\n"
"        \n"
"        n += step(.0, beta)*step(beta, 1.)*step(0., alpha);\n"
"        dlinesegment(x, ptsi, ptsip1, da);\n"
"        ret = min(ret, da);\n"
"    }\n"
"    \n"
"    ret = mix(ret, -ret, mod(n, 2.));\n"
"    \n"
"    ret = max(d,-ret);\n"
"    ret /= .7;\n"
"}\n"
"\0";
const char *sub_source = "#version 130\n\n"
"\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void sub(in vec2 sda, in vec2 sdb, out vec2 sdf)\n"
"{\n"
"    sdf = (sda.x>sdb.x)?abs(sda):abs(sdb)*c.zx;\n"
"}\n"
"\0";
const char *doctahedron_source = "#version 130\n\n"
"\n"
"void doctahedron(in vec3 x, in float h, in float w, out float d)\n"
"{\n"
"    x.xz = abs(x.xz);\n"
"    x.y = abs(x.y)-h;\n"
"    d = max(x.z,x.x)+(x.y*w);    \n"
"}\n"
"\0";
const char *ocean_source = "#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void hash11(in float p, out float d);\n"
"void hash12(in vec2 p, out float d);\n"
"void hash21(in float p, out vec2 d);\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void hash31(in float p, out vec3 d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"\n"
"void gerst(in vec2 x, out float z)\n"
"{\n"
"    float df, \n"
"        A = 1.,\n"
"        da;\n"
"    vec2 dk,\n"
"        k;\n"
"    \n"
"    z = 0.;\n"
"    \n"
"    for(float f = 1.; f < 6.; f *= 1.1)\n"
"    {\n"
"        hash11(f,df);\n"
"        f *= (.95+.2*df);\n"
"        hash21(f+2337.,k);\n"
"        k *= 64./f+.5;\n"
"        hash11(f+1337., da);\n"
"        A *= (1.+.3*da);\n"
"        \n"
"        z += A*pow(.5*(1.+sin(dot(k,x)+f*iTime)),2.);\n"
"    }\n"
"    \n"
"}\n"
"\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    float g;\n"
"    gerst(x.xy, g);\n"
"    sdf = vec2(x.z-.002*g, 1.);\n"
"    sdf.x = abs(sdf.x) - .002;\n"
"    \n"
"    add(sdf, vec2(x.z+.2, 2.), sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"void palette(in float scale, out vec3 col)\n"
"{\n"
"    const int N = 5;\n"
"    const vec3 colors[N] = vec3[N](\n"
"//             vec3(0.27,0.13,0.26),\n"
"//             vec3(0.43,0.21,0.33),\n"
"//             vec3(0.69,0.36,0.42),\n"
"//             vec3(0.87,0.52,0.45),\n"
"//             vec3(0.99,0.68,0.53)\n"
"vec3(0.04,0.04,0.15),\n"
"vec3(0.18,0.32,0.46),\n"
"vec3(0.66,0.43,0.62),\n"
"vec3(0.96,0.78,0.88),\n"
"vec3(0.40,0.00,0.18)\n"
"    );\n"
"	float index = floor(scale*float(N)), \n"
"        remainder = scale*float(N)-index;\n"
"    col = mix(colors[int(index)],colors[int(index)+1], remainder);\n"
"}\n"
"\n"
"float dspiral(vec2 x, float a, float d);\n"
"\n"
"void colorize(in vec2 x, inout vec3 col)\n"
"{\n"
"    float v, n = 64., r;\n"
"    vec2 ind;\n"
"    dvoronoi(n*x, v, ind, r);\n"
"    rand(ind, r);\n"
"    vec2 y = x-ind/n;\n"
"    vec3 c1;\n"
"    rand(ind+1337., c1.x);\n"
"    rand(ind+2337., c1.y);\n"
"    rand(ind+3337., c1.z);\n"
"    c1 *= vec3(1.,.7,.3);\n"
"    c1 = .5+.5*c1;\n"
"    c1 *= vec3(.4,.6,1.);\n"
"    float d = length(y)-.0002*r;\n"
"    if(r > .75)\n"
"        col = mix(col, c1, sm(d));\n"
"//     r *= cos(pi*x.y);\n"
"    if(r>.5)\n"
"    {\n"
"        col = mix(col, mix(col, 2.*c1, .8), sm(d-.004*r*r));\n"
"        col = mix(col, mix(col, 3.*c1, .4), sm(d-.01*r*r));\n"
"    }\n"
"    \n"
"    float cpa;\n"
"    dvoronoi(2.*n*x, v, ind, cpa);\n"
"    y = x-ind/n/2.;\n"
"    rand(ind, r);\n"
"    d = length(y)-.002*r;\n"
"    col = mix(col, c.xxx, sm(d));\n"
"    \n"
"    lfnoise(x.xy-v*v*v, d);\n"
"    col = mix(col, c.yyy, .5+.5*d);\n"
"    \n"
"    col = .6*col+.3*step(.8,col);\n"
"    col *= 2.;\n"
"    \n"
"    v = dspiral(x, .1,.01);\n"
"    col = mix(col, c.yyy, 1.-sm(v*6.e-3));\n"
"    col = mix(col, 2.5*col, sm(v*2.e-3));\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    \n"
"    vec3 col = c.yyy,\n"
"        o = .5*c.yyx+c.yzy,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x;\n"
"    int N = 150,\n"
"        i;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"\n"
"    vec3 c1;\n"
"    float d = -(o.z-.15)/dir.z;\n"
"    \n"
"    vec3 o0, dir0;\n"
"    float d0;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-4) break;\n"
"        d += s.x;\n"
"//         d += min(s.x,1.e-2);\n"
"        //d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = c.yyx;\n"
"        normal(x,n, 1.e-4);\n"
"        \n"
"        if(s.y == 1.)\n"
"        {\n"
"            palette(x.z/.22, col);\n"
"\n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + 1.6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"        \n"
"        o = x;\n"
"        d = 1.e-2;\n"
"        dir = refract(dir,n,.5);\n"
"        vec3 c1;\n"
"        \n"
"        for(i = 0; i<N; ++i)\n"
"        {\n"
"            x = o + d * dir;\n"
"            scene(x,s);\n"
"            if(s.x < 1.e-3)break;\n"
"            d += s.x;\n"
"    //         d += min(s.x,1.e-1);\n"
"            //d += s.x;\n"
"        }\n"
"        \n"
"        if(i < N)\n"
"        {\n"
"            vec3 l = c.yyx;\n"
"            normal(x,n, 2.e-3);\n"
"            \n"
"            \n"
"            if(s.y == 1.)\n"
"            {\n"
"                palette(x.z/.22, c1);\n"
"\n"
"                c1 = .1*c1 \n"
"                    + .1*c1*dot(l, n)\n"
"                    + 1.6*c1*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"            }\n"
"            else if(s.y == 2.)\n"
"            {\n"
"                c1 = vec3(0.26,0.16,0.32);\n"
"//                 float v, cv;\n"
"//                 vec2 ind;\n"
"//                 dvoronoi(12.*x.xy, v, ind, cv);\n"
"//                 c1 = mix(c1, c.xxx, sm(abs(v)-.02));\n"
"                float v = .5+.5*sin(100.*x.y);\n"
"                c1 = mix(c1,2.*c1, v);\n"
"                \n"
"                c1 = .1*c1 \n"
"                    + .1*c1*dot(l, n)\n"
"                    + 1.6*c1*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"            }\n"
"        }\n"
"        col = mix(col, c1, .1);\n"
"    }\n"
"\n"
"    col = 3.*col*col;\n"
"    \n"
"    //col = mix(col, c.yyy, tanh(2.e-1*d));\n"
"   \n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\n"
"\0";
const char *logo210_source = "/* Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" * \n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" * \n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" * \n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
" \n"
"#version 130\n \n"
" \n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"float a = 1.0;\n"
"\n"
"float nbeats, iScale;\n"
"\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"void rot3(in vec3 p, out mat3 rot);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void dbox210(in vec3 x, in float size, out vec2 sdf);\n"
"\n"
"mat3 R;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    sdf = c.xy;\n"
"    \n"
"    float d, da;\n"
"    \n"
"    rot3(vec3(-pi/2.,0.,pi/2.), R);\n"
"    x = R * x;\n"
"    \n"
"    vec2 sda = c.xy;\n"
"    \n"
"	dbox210(x+.1*c.xyy, .5, sdf);\n"
"	rot3(vec3(pi/2.,0.,pi/2.), R);\n"
"    x = R * x;\n"
"    //add(sdf,sda,sdf);\n"
"    \n"
"    dbox210(x,5.,sda);\n"
"    add(sdf,sda,sdf);\n"
"    \n"
"    rot3(vec3(pi/2.,-pi/2.,pi/2.), R);\n"
"    x = R * x;\n"
"    \n"
"    dbox210(x-2.*c.yxy,50.,sda);\n"
"    add(sdf,sda,sdf);\n"
"    \n"
"    stroke(sdf.x,.001, sdf.x);\n"
"    \n"
"    dbox3(x, 100.*c.xxx, sda.x);\n"
"    sda.y = 2.;\n"
"    \n"
"    add(sdf, sda*c.zx, sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord )\n"
"{\n"
"    float a = iResolution.x/iResolution.y;\n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0);\n"
"    \n"
"    vec3 col = c.xxx;\n"
"    \n"
"    float d = 0.;\n"
"    vec2 s;\n"
"    vec3 o, t, dir, x, n;\n"
"    \n"
"    mat3 Ra, Rb;\n"
"    rot3(mix(c.yyy,vec3(-5.7884463,2.4242211,0.3463173),clamp((iTime-6.)/1.5,0.,1.)), Ra);\n"
"    rot3(mix(c.yyy,vec3(-2.*pi+5.7884463,-2.4242211,-0.3463173)+pi*c.xyy,clamp((iTime-10.),0.,1.)), Rb);\n"
"    \n"
"    \n"
"    o = Ra * mix(mix(mix(c.yyy-.005*c.yyx,c.yyx,clamp(iTime/2.,0.,1.)),10.*c.yyx,clamp((iTime-2.)/2.,0.,1.)), 100.*c.yyx, clamp((iTime-4.)/2.,0.,1.));\n"
"	t = c.yyy;\n"
"    int N = 650,\n"
"        i;\n"
"    dir = Rb * Ra *normalize(vec3(uv,-1.));//normalize(t-o);\n"
"//     dir = mix(dir, normalize(vec3(uv,1.)), clamp(iTime-10.,0.,1.));\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"        x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-4)break;\n"
"        d += s.x;\n"
"    }\n"
"        \n"
"    if(s.x < 1.e-4)\n"
"    {\n"
"        normal(x,n, 5.e-4);\n"
"        vec3 l = normalize(x+.1*n);\n"
"        \n"
"        if(s.y == 1.)\n"
"        {\n"
"            // cube color\n"
"            col = vec3(0.27,0.36,0.48);\n"
"            col = .3*col\n"
"                + .4*col * abs(dot(l,n))\n"
"                + .6 * col * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"        }\n"
"        else if(s.y == 2.)\n"
"        {\n"
"            col = .7*c.xxx;\n"
"            col = .5*col\n"
"                + .4*col * abs(dot(l,n))\n"
"                + .8 * col * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"            \n"
"            vec3 c1 = c.yyy;\n"
"            \n"
"            o = x;\n"
"            dir = reflect(dir,n);\n"
"            d = 1.e-1;\n"
"            \n"
"            N = 150;\n"
"            \n"
"            for(i = 0; i<N; ++i)\n"
"            {\n"
"                x = o + d * dir;\n"
"                scene(x,s);\n"
"                if(s.x < 1.e-4)break;\n"
"                d += s.x;\n"
"            }\n"
"                \n"
"            if(s.x < 1.e-4)\n"
"            {\n"
"                normal(x,n, 5.e-4);\n"
"                vec3 l = normalize(x+.1*n);\n"
"\n"
"                if(s.y == 1.)\n"
"                {\n"
"                    c1 = vec3(0.27,0.36,0.48);\n"
"                    c1 = .3*c1\n"
"                        + .4*c1 * abs(dot(l,n))\n"
"                        + .6 * c1 * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"                }\n"
"                else if(s.y == 2.)\n"
"                {\n"
"                    c1 = .7*c.xxx;\n"
"                    c1 = .5*c1\n"
"                        + .4*c1 * abs(dot(l,n))\n"
"                        + .8 * c1 * abs(pow(dot(reflect(-l,n),dir),3.));\n"
"                }\n"
"                c1 = clamp(c1, 0., 1.);\n"
"                \n"
"                col = mix(col, c1, .2);\n"
"            }\n"
"            \n"
"            col = clamp(col, 0., 1.);\n"
"        }\n"
"        \n"
"    }\n"
"    col = mix(col,c.xxx,smoothstep(0.,1.,iTime-11.));\n"
"    \n"
"    col = mix(vec3(0.18,0.24,0.31), col, clamp(iTime,0.,1.));\n"
"    \n"
"    fragColor = vec4(clamp(col,0.,1.),1.0);\n"
"}\n"
"\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\0";
const char *graffiti_source = "/* Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" * \n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" * \n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" * \n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
"\n"
"#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"float a = 1.0;\n"
"\n"
"void hash22(in vec2 x, out vec2 y);\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void dspline2(in vec2 x, in vec2 p0, in vec2 p1, in vec2 p2, out float ds);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"void d_h(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(abs(x.x)-.1, abs(x.y)), vec2(.15,.25), vec2(.05,.25), vec2(.05,0.), d);\n"
"    dlinesegment(x, vec2(-.075,0.), vec2(.075,0.), da);\n"
"    smoothmin(d, da, .1, d);\n"
"}\n"
"\n"
"void d_a(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(abs(x.x)-.1, x.y), vec2(.15,-.25), vec2(.05,-.25), vec2(.05, 0.), d);\n"
"    dspline2(vec2(abs(x.x)-.1, x.y), vec2(.05,0.), vec2(.05,.25), vec2(-.1,.25), da);\n"
"    d = min(d,da);\n"
"    dlinesegment(x, vec2(-.075,0.), vec2(.075,0.), da);\n"
"    smoothmin(d, da, .1, d);\n"
"}\n"
"\n"
"void d_r(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(x.x, abs(x.y)), vec2(-.15,.25), vec2(-.05,.25), vec2(-.05,0.), d);\n"
"    dspline2(vec2(x.x,abs(x.y-.1)-.15), vec2(.0,-.05), vec2(.25,.05), vec2(.25,-.15), da);\n"
"    smoothmin(d,da,.1,d);\n"
"    dspline2(x,vec2(0.,-.05), vec2(0.,-.25), vec2(.35,-.25), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void d_d(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(x.x, abs(x.y)), vec2(-.15,.25), vec2(-.05,.25), vec2(-.05,0.), d);\n"
"    dspline2(vec2(x.x,abs(x.y)-.1), vec2(-.05,.15), vec2(.25,.25), vec2(.25,-.1), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void d_c(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(x.x, abs(x.y)), vec2(-.15,.25), vec2(-.05,.25), vec2(-.05,0.), d);\n"
"    dspline2(vec2(x.x,abs(x.y)-.1), vec2(-.05,.15), vec2(.25,.25), vec2(.25,0.), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void d_y(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(abs(x.x)-.2, x.y), vec2(-.05,0.25), vec2(-.05,.1), vec2(-.2,.1), d);\n"
"    dlinesegment(x, vec2(0.,-.25), vec2(0.,.1), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void d_b(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(x.x, abs(x.y)), vec2(-.15,.25), vec2(-.05,.25), vec2(-.05,0.), d);\n"
"    dspline2(vec2(x.x,abs(abs(x.y)-.125)-.15), vec2(.0,-.05), vec2(.25,.05), vec2(.25,-.15), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void d_e(in vec2 x, out float d)\n"
"{\n"
"    float da;\n"
"    dspline2(vec2(x.x, abs(x.y)), vec2(-.15,.25), vec2(-.05,.25), vec2(-.05,0.), d);\n"
"    dspline2(vec2(x.x,abs(x.y)-.1), vec2(-.05,.05), vec2(-.05,.15), vec2(.25,.15), da);\n"
"    smoothmin(d,da,.1,d);\n"
"    dlinesegment(x,vec2(-.05,0.), vec2(.15,0.), da);\n"
"    smoothmin(d,da,.1,d);\n"
"}\n"
"\n"
"void dhardcyber(in vec2 x, out float d)\n"
"{\n"
"//     x = floor(96.*x)/96.;\n"
"    x *= 3.;\n"
"    float da;\n"
"    d_h(x+1.8*c.xy,d);\n"
"    d_a(x+1.3*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_r(x+.9*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_d(x+.4*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_c(x-.1*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_y(x-.6*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_b(x-.925*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_e(x-1.4*c.xy,da);\n"
"    d = min(d,da);\n"
"    d_r(x-1.8*c.xy,da);\n"
"    d = min(d,da);\n"
"    \n"
"    stroke(d, .05, d);\n"
"    \n"
"    d /= 3.;\n"
"}\n"
"\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void palette(in float scale, out vec3 col)\n"
"{\n"
"    const int N = 5;\n"
"    const vec3 colors[N] = vec3[N](\n"
"            vec3(0.27,0.13,0.26),\n"
"            vec3(0.43,0.21,0.33),\n"
"            vec3(0.69,0.36,0.42),\n"
"            vec3(0.87,0.52,0.45),\n"
"            vec3(0.99,0.68,0.53)\n"
"    );\n"
"	float index = floor(scale*float(N)), \n"
"        remainder = scale*float(N)-index;\n"
"    col = mix(colors[int(index)],colors[int(index)+1], remainder);\n"
"}\n"
"\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void zextrude(in float z, in float d2d, in float h, out float d);\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{    \n"
"    dhardcyber(x.xy, sdf.x);\n"
"    zextrude(x.z, -sdf.x, mix(.0,.1,clamp((iTime-3.5)/.5,0.,1.)), sdf.x);\n"
"    smoothmin(sdf.x, x.z, mix(.001,.1,clamp((iTime-3.5)/.5,0.,1.)), sdf.x);\n"
"    sdf.y = 1.;\n"
"    stroke(sdf.x, mix(0.,.01,clamp((iTime-3.5)/.5,0.,1.)), sdf.x);\n"
"//     sdf.x = abs(sdf.x);\n"
"//     sdf.x /= 4.;\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"void colorize(in vec2 uv, inout vec3 col)\n"
"{\n"
"    vec3 c1;\n"
"    float d = floor(8.*(.5+.4*tanh(6.*uv.y+uv.x)))/8.;\n"
"    vec2 ind;\n"
"    float v,vn;\n"
"    dvoronoi(16.*uv, v, ind,vn);\n"
"    float r;\n"
"    rand(ind,r);\n"
"    d = (uv.y+.25)/.5-.2*r;\n"
"    palette(clamp(d,0.,1.),c1);\n"
"//     c1 = mix(c1, c.yyy, sm(abs(v)-.02));\n"
"    col = (.5+.5*r)*c.xxx;\n"
"    \n"
"    dhardcyber(uv, d);\n"
"    d = mix(1.,d,clamp((iTime-3.)/.5,0.,1.));\n"
"    col = mix(col, .7*c.xxx, sm(d-.04));\n"
"    col = mix(col, c1, sm(d));\n"
"    col = mix(col, c.yyy, sm(abs(d-.01)-.01));\n"
"    col = mix(col, vec3(0.99,0.68,0.53), sm(abs(d-.005)-.005));\n"
"    col = mix(col, 1.2*vec3(0.99,0.68,0.53), sm(abs(d-.005)-.001));\n"
"    \n"
"    col = mix(col, c.yyy, sm(abs(v)-.02));\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    a = iResolution.x/iResolution.y;\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution)/iResolution.y,\n"
"        s;\n"
"    //uv.x *= 1.-.1*abs(sin(2.*pi*uv.y));\n"
"    vec3 col = c.xxx,\n"
"        o = c.yyx+.4*c.yzy,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x;\n"
"    int N = 150,\n"
"        i;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"\n"
"    vec3 c1;\n"
"    float d = -o.z/dir.z;\n"
"    \n"
"    d = -(o.z-.1)/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(x.z<0.)\n"
"        {\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += s.x;\n"
"//         d += min(s.x,1.e-1);\n"
"        //d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = x+c.yyx;\n"
"        normal(x,n, 2.e-6);\n"
"        colorize(x.xy, col);\n"
"        col = .1*col \n"
"            + .1*col*dot(l, n)\n"
"            + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        col = mix(c.xxx, col, clamp(iTime/(1.+length(x.xy)),0.,1.));\n"
"    }\n"
"    \n"
"    col = 2.*col*col;\n"
"    col = mix(col, c.yyy, clamp(iTime-9.,0.,1.));\n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.), 1.);\n"
"}\n"
"\0";
const char *starsky_source = "/* Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" * \n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" * \n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" * \n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
" \n"
"#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"float a = 1.0;\n"
"\n"
"void hash22(in vec2 x, out vec2 y);\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void mfnoise(in vec2 x, in float d, in float b, in float e, out float n);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 z, out float dv);\n"
"float dspiral(vec2 x, float a, float d);\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"float dspiral(vec2 x, float a, float d)\n"
"{\n"
"    float p = atan(x.y, x.x),\n"
"        n = floor((abs(length(x)-a*p)+d*p)/(2.*pi*a));\n"
"    p += (n*2.+1.)*pi;\n"
"    return -abs(length(x)-a*p)+d*p;\n"
"}\n"
"\n"
"void stroke(in float d0, in float s, out float d);\n"
"void colorize(in vec2 x, inout vec3 col)\n"
"{\n"
"    float v, n = 64., r, vn;\n"
"    vec2 ind;\n"
"    dvoronoi(n*x, v, ind, vn);\n"
"    rand(ind, r);\n"
"    vec2 y = x-ind/n;\n"
"    vec3 c1;\n"
"    rand(ind+1337., c1.x);\n"
"    rand(ind+2337., c1.y);\n"
"    rand(ind+3337., c1.z);\n"
"    c1 *= vec3(1.,.7,.3);\n"
"    c1 = .5+.5*c1;\n"
"    c1 *= vec3(.4,.6,1.);\n"
"    float d = length(y)-.002*r;\n"
"    if(r > .75)\n"
"        col = mix(col, c1, sm(d));\n"
"//     r *= cos(pi*x.y);\n"
"    if(r>.5)\n"
"    {\n"
"        col = mix(col, mix(col, 2.*c1, .8), sm(d-.004*r*r));\n"
"        col = mix(col, mix(col, 3.*c1, .4), sm(d-.01*r*r));\n"
"    }\n"
"    \n"
"    dvoronoi(2.*n*x, v, ind, vn);\n"
"    y = x-ind/n/2.;\n"
"    rand(ind, r);\n"
"    d = length(y)-.002*r;\n"
"    col = mix(col, c.xxx, sm(d));\n"
"    \n"
"    lfnoise(x.xy-v*v*v, d);\n"
"    col = mix(col, c.yyy, .5+.5*d);\n"
"    \n"
"    col = .6*col+.3*step(.8,col);\n"
"    col *= 2.;\n"
"    \n"
"    v = dspiral(x, .1,.01);\n"
"    col = mix(col, c.yyy, 1.-sm(v*6.e-3));\n"
"    col = mix(col, 2.5*col, sm(v*2.e-3));\n"
"}\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void street(in vec2 x, out vec3 col)\n"
"{\n"
"    x.y += .3*iTime;\n"
"    \n"
"    float dx;\n"
"    lfnoise(x.y*c.xx, dx);\n"
"    x.x += .1*dx;\n"
"    \n"
"    col = .4*c.xxx;\n"
"    float da = mod(x.y, .1)-.05;\n"
"    dbox(vec2(x.x,da), vec2(.005,.025), da);\n"
"    col = mix(col, c.xxx, sm(da));\n"
"    col = mix(col, c.xxx, sm(abs(abs(x.x)-.1)-.01));\n"
"    \n"
"    float n;\n"
"    mfnoise(x.xy, mix(8.,1.,smoothstep(.4,1.6,abs(x.x))),200., .35,n);\n"
"    col = mix(col, .5*col, .5+.5*n);\n"
"    \n"
"    col = mix(col, .6*c.xxx, abs(n)-.1);\n"
"    \n"
"    vec2 ind;\n"
"    float v, vn;\n"
"    dvoronoi(256.*x, v, ind, vn);\n"
"    ind = x-ind/256.;\n"
"    col = mix(col, .0*c.xxx, sm(length(ind)-.0001));\n"
"}\n"
"\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    x.y += .3*iTime;\n"
"    \n"
"    float dx;\n"
"    lfnoise((x.y)*c.xx, dx);\n"
"    x.x += .1*dx;\n"
"    \n"
"    sdf = c.xx;\n"
"    float n;\n"
"    mfnoise(x.xy, mix(8.,1.,smoothstep(.4,1.6,abs(x.x))),2000., mix(.35,.45,smoothstep(.4,1.6,abs(x.x))),n);\n"
"    float n0 = n;\n"
"    n = .5+.5*n;\n"
"    n *= smoothstep(.1,.3,abs(x.x))+smoothstep(.4,1.2,abs(x.x));\n"
"    sdf.x = x.z-.1*n;\n"
"    sdf.y = 1.;\n"
"    \n"
"    float d;\n"
"    dbox3(x-c.yyx*.005*step(.1,abs(n0)-.01), vec3(.1,1.e3,.001+.01*n0), d);\n"
"    \n"
"    add(sdf, vec2(d, 2.), sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"void palette(in float scale, out vec3 col)\n"
"{\n"
"    const int N = 5;\n"
"    const vec3 colors[N] = vec3[N](\n"
"            vec3(0.27,0.13,0.26),\n"
"            vec3(0.43,0.21,0.33),\n"
"            vec3(0.69,0.36,0.42),\n"
"            vec3(0.87,0.52,0.45),\n"
"            vec3(0.99,0.68,0.53)\n"
"// vec3(0.04,0.04,0.15),\n"
"// vec3(0.18,0.32,0.46),\n"
"// vec3(0.66,0.43,0.62),\n"
"// vec3(0.96,0.78,0.88),\n"
"// vec3(0.40,0.00,0.18)\n"
"    );\n"
"	float index = floor(scale*float(N)), \n"
"        remainder = scale*float(N)-index;\n"
"    col = mix(colors[int(index)],colors[int(index)+1], remainder);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    a = iResolution.x/iResolution.y;\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution)/iResolution.y,\n"
"        s;\n"
"\n"
"        vec3 col = c.yyy,\n"
"        o = .3*c.yyx+c.yzy,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x;\n"
"    int N = 250,\n"
"        i;\n"
"    t = uv.x * r + uv.y * u;\n"
"    \n"
"    dir = normalize(t-o);\n"
"\n"
"    vec3 c1;\n"
"    float d = -(o.z-.2)/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(x.z<0.)\n"
"        {\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += s.x;\n"
"//         d += min(s.x,1.e-1);\n"
"        //d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = c.yyx;\n"
"        normal(x,n, 2.e-6);\n"
"        \n"
"        if(s.y == 1.)\n"
"        {\n"
"            palette(x.z/.22, col);\n"
"//             float na;\n"
"//             mfnoise(x.xy, mix(8.,1.,smoothstep(.4,1.6,abs(x.x))),2000., mix(.35,.45,smoothstep(.4,1.6,abs(x.x))),na);\n"
"//             col = mix(col, 2.*col, abs(abs(na)-.1)-.001);\n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"        else if(s.y == 2.)\n"
"        {\n"
"            street(x.xy, col);\n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"        else \n"
"        {\n"
"            colorize(x.xy, col);\n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .8*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"        if(x.z>.05)\n"
"            col = mix(col, 3.*col, smoothstep(.95,.951, n.z));\n"
"    }\n"
"\n"
"    col = 12.*col*col;\n"
"    \n"
"    col = mix(col, c.yyy, tanh(2.e-1*d));\n"
"    \n"
"    vec3 c2;\n"
"    colorize(4.*uv, c2);\n"
"    col = mix(col, 2.*c2, smoothstep(.3,.5, uv.y));\n"
"    \n"
"    col = mix(c.yyy, col, clamp(iTime,0.,1.));\n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.), 1.);\n"
"}\n"
"\0";
const char *text_source = "/* Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" * \n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" * \n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" * \n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
" \n"
"#version 130\n\n"
"\n"
"uniform float iFontWidth, iTime;\n"
"uniform vec2 iResolution;\n"
"uniform sampler2D iChannel0, iFont;\n"
"uniform float iFSAA;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"out vec4 gl_FragColor;\n"
"\n"
"// Global constants\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"const float pi = acos(-1.);\n"
"float a; // Aspect ratio\n"
"\n"
"void rand(in vec2 x, out float num);\n"
"void lfnoise(in vec2 t, out float num);\n"
"void rshort(in float off, out float val);\n"
"void rfloat(in float off, out float val);\n"
"void dbox(in vec2 x, in vec2 b, out float dst);\n"
"void dcircle(in vec2 x, out float d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void drhomboid(in vec2 x, in vec2 b, in float tilt, out float dst);\n"
"void dcirclesegment(in vec2 x, in float r, in float p0, in float p1, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void dglyph(in vec2 x, in float ordinal, in float size, out float dst);\n"
"void dstring(in vec2 x, in float ordinal, in float size, out float dst);\n"
"void dfloat(in vec2 x, in float num, in float size, out float dst);\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"void dint(in vec2 x, in float num, in float size, in float ndigits, out float dst);\n"
"void dtime(in vec2 x, in float num, in float size, out float dst);\n"
"\n"
"void addwindow(in vec2 uv, inout vec3 col, in vec2 dimension);\n"
"\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord )\n"
"{\n"
"    a = iResolution.x/iResolution.y;\n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0);\n"
"    \n"
"    float d;\n"
"\n"
"    vec4 old = c.yyyy, \n"
"        new = c.yyyy;\n"
"    \n"
"    float bound = sqrt(iFSAA)-1.;\n"
"\n"
"    for(float i = -.5*bound; i<=.5*bound; i+=1.)\n"
"        for(float j=-.5*bound; j<=.5*bound; j+=1.)\n"
"        {\n"
"            old.gba += texture(iChannel0, (fragCoord+vec2(i,j)*3./max(bound, 1.))/iResolution.xy).xyz;\n"
"        }\n"
"    old.gba /= iFSAA;\n"
"    \n"
"    new = old;\n"
"    \n"
"    if(uv.y > .38) // Ui overlay with time counter and credits\n"
"    {\n"
"        addwindow(uv-.45*vec2(-.45*a,1.-2.*.008*c.yx), new.gba, vec2(.4,.04));\n"
"        addwindow((uv-.45*vec2(.97*a,1.-2.*.008*c.yx))*c.zx, new.gba, vec2(.1,.04));\n"
"        float da;\n"
"        dstring((uv-.45*vec2(-.55*a,1.+4.*.008)), 9., .004, d);\n"
"        dstring((uv-.45*vec2(-.55*a,1.+2.*.008)), 10., .004, da);\n"
"        d = min(d,da);\n"
"        dstring((uv-.45*vec2(-.55*a,1.)), 11., .004, da);\n"
"        d = min(d,da);\n"
"        dstring((uv-.45*vec2(-.55*a,1.-2.*.008)), 12., .004, da);\n"
"        d = min(d,da);\n"
"        dstring((uv-.45*vec2(-.55*a,1.-4.*.008)), 13., .004, da);\n"
"        d = min(d,da);\n"
"        new.gba = mix(new.gba, mix(new.gba, c.xxx, 1.), sm(d));\n"
"        \n"
"        // Add Static text\n"
"        dstring((uv-.45*vec2(-.85*a,1.)), 3., .02, d); // Team210\n"
"        \n"
"        new.gba = mix(new.gba, mix(new.gba,c.xxx,.5), sm(d));\n"
"        stroke(d-.002, .002, d);\n"
"        new.gba = mix(new.gba, vec3(1.00,0.40,0.39), sm(d));\n"
"\n"
"        // Add time overlay\n"
"        dtime((uv-.45*vec2(.975*a,1.05)), iTime+11., .01, d);\n"
"        new.gba = mix(new.gba, c.xxx, sm(d));\n"
"        \n"
"        // Add exact millisecond\n"
"        dint(uv-.45*vec2(.975*a,1.0), floor(1.e3*fract(iTime)), .01, 4., d);\n"
"//         new.gba = mix(new.gba, vec3(1.00,0.40,0.39), sm(d));\n"
"        stroke(d-.001, .0005, d);\n"
"        new.gba = mix(new.gba, c.xxx, sm(d));\n"
"    }\n"
"    \n"
"    if(iTime < 20.)\n"
"    {\n"
"        float sc = clamp(iTime-10.,0.,1.)*(1.-clamp(iTime-18.,0.,1.)),\n"
"            da;\n"
"        \n"
"        // window\n"
"        vec3 c1 = new.gba;\n"
"        addwindow(uv, c1, vec2(.72,.15));\n"
"        new.gba = mix(new.gba, c1, sc);\n"
"        \n"
"        // No more partycoding this time!\n"
"        dstring(uv-vec2(-.5,.05), 5., .02, d);\n"
"        \n"
"        // yeah sure.\n"
"        dstring(uv-vec2(-.5,0.), 6., .02, da);\n"
"        d = min(d, da);\n"
"        \n"
"        // well, that worked!\n"
"        dstring(uv-vec2(-.5,-.05), 7., .02, da);\n"
"        d = min(d, da);\n"
"        \n"
"        d = mix(1., d, sc);\n"
"        \n"
"        new.gba = mix(new.gba, c.xxx, sm(d));\n"
"    }\n"
"    else if(iTime < 32.) \n"
"    {\n"
"        float sc = smoothstep(0.,1.,clamp(iTime-25.,0.,1.))*(1.-smoothstep(0.,1.,clamp(iTime-30.,0.,1.)));\n"
"        \n"
"        vec3 c1 = new.gba;\n"
"        addwindow(uv-vec2(0.,-.3), c1, vec2(.15,.1));\n"
"        \n"
"        dstring((uv-vec2(-.085,-.3)), 3., .02, d); // Team210\n"
"        float da;\n"
"        dstring((uv-vec2(-.08,-.35)), 26., .02, da); // present\n"
"        d = min(d,da);\n"
"\n"
"        c1 = mix(c1,c.xxx, sm(d));\n"
"        \n"
"        new.gba = mix(new.gba, c1, sc);\n"
"    }\n"
"//     else if(iTime < 44.)\n"
"//     {\n"
"//         float da, db;\n"
"//         \n"
"//         // Once\n"
"//         dstring((uv-vec2(-.3,.3)), 21., .1, da);\n"
"//         \n"
"//         db = abs(mod(uv.x+uv.y,.3)-.15)-.075;\n"
"//         vec3 c1 = mix(mix(new.gba,.3*c.xxx,.5), c.xxx, sm(db));\n"
"//         \n"
"//         db = smoothstep(33.,34.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         new.gba = mix(new.gba, c1, sm(da));\n"
"//         \n"
"//         stroke(da-.02,.001,da);\n"
"//         new.gba = mix(new.gba, c.xxx, sm(da));\n"
"//         \n"
"//         // You\n"
"//         dstring(uv-vec2(.35,.34), 22., .05, da);\n"
"//         \n"
"//         dbox(uv-vec2(.35,.34), vec2(.15,.06), db);\n"
"//         db = max(db,-da);\n"
"//         float mx = smoothstep(34.,35., iTime);\n"
"//         db = mix(1., db, mx);\n"
"//         new.gba = mix(new.gba, c.xxx, sm(db));\n"
"//         \n"
"//         // Offend\n"
"//         dstring(uv-vec2(.25,.24), 23., .0277, da);\n"
"//         mx = smoothstep(35.,36.,iTime);\n"
"//         da = mix(1., da, mx);\n"
"//         new.gba = mix(new.gba, .8*c.xxy, sm(da));\n"
"//         \n"
"//         // You\n"
"//         dstring(uv-vec2(.25,.15), 22., .05, da);\n"
"//         mx = smoothstep(36.,37.,iTime);\n"
"//         da = mix(1., da, mx);\n"
"//         new.gba = mix(new.gba, .8*c.xxy, sm(da));\n"
"//         \n"
"//         // Cannot\n"
"//         dstring((uv-vec2(.45,.05)).yx*c.zx, 24., .05, da);\n"
"//         \n"
"//         dbox((uv-vec2(.45,-.1)), vec2(.05,.3), db);\n"
"//         db = max(db,-da);\n"
"//         mx = smoothstep(37.,38., iTime);\n"
"//         db = mix(1., db, mx);\n"
"//         new.gba = mix(new.gba, c.xxx, sm(db));\n"
"// \n"
"//         // Stop\n"
"//         dstring((uv-vec2(.6,.1)).yx*c.zx, 25., .1, da);\n"
"//         \n"
"//         db = smoothstep(38.,39.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         new.gba = mix(new.gba, c1, sm(da));\n"
"//         \n"
"//         stroke(da-.02,.001,da);\n"
"//         new.gba = mix(new.gba, c.xxx, sm(da));\n"
"//     }\n"
"//     else if(iTime < 60.)\n"
"//     {\n"
"//         //vec3(0.93,0.36,0.44)\n"
"//         float da, db;\n"
"//         \n"
"//         db = abs(mod(uv.x+uv.y,.3)-.15)-.075;\n"
"//         vec3 c1 = mix(mix(new.gba,vec3(0.93,0.36,0.44),.5), c.xxx, sm(db));\n"
"//         \n"
"//         // Banging your head against \n"
"//         dstring((uv-vec2(-.3,.3)), 38., .02, da);\n"
"//         \n"
"//         db = smoothstep(45.,46.,iTime)-smoothstep(50.,51.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         stroke(da-.005,.0025,db);\n"
"//         new.gba = mix(new.gba, c.yyy, sm(db));\n"
"//         \n"
"//         new.gba = mix(new.gba, c1, sm(da-.0025));\n"
"//         \n"
"//         db = da+.0025;\n"
"//         new.gba = mix(new.gba,2.*c1, sm(db));\n"
"//         \n"
"//         // a wall for one hour burns \n"
"//         dstring((uv-vec2(-.3,.25)), 39., .02, da);\n"
"//         \n"
"//         db = smoothstep(46.,47.,iTime)-smoothstep(51.,52.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         stroke(da-.005,.0025,db);\n"
"//         new.gba = mix(new.gba,c.yyy, sm(db));\n"
"//         \n"
"//         new.gba = mix(new.gba, c1, sm(da-.0025));\n"
"//         \n"
"//         db = da+.0025;\n"
"//         new.gba = mix(new.gba,2.*c1, sm(db));\n"
"//         \n"
"//         // 150 kilocalories. Want to\n"
"//         dstring((uv-vec2(-.3,.2)), 40., .02, da);\n"
"//         \n"
"//         db = smoothstep(47.,48.,iTime)-smoothstep(52.,53.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         stroke(da-.005,.0025,db);\n"
"//         new.gba = mix(new.gba,c.yyy, sm(db));\n"
"//         \n"
"//         new.gba = mix(new.gba, c1, sm(da-.0025));\n"
"//         \n"
"//         db = da+.0025;\n"
"//         new.gba = mix(new.gba, 2.*c1, sm(db));\n"
"//         \n"
"//         // start losing some weight?\n"
"//         dstring((uv-vec2(-.3,.15)), 41., .02, da);\n"
"//         \n"
"//         db = smoothstep(48.,49.,iTime)-smoothstep(53.,54.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         stroke(da-.005,.0025,db);\n"
"//         new.gba = mix(new.gba, c.yyy, sm(db));\n"
"//         \n"
"//         new.gba = mix(new.gba, c1, sm(da-.0025));\n"
"//         \n"
"//         db = da+.0025;\n"
"//         new.gba = mix(new.gba, 2.*c1, sm(db));\n"
"//         \n"
"//         new.gba = clamp(new.gba,0.,1.);\n"
"//     }\n"
"//     else if(iTime < 130.)\n"
"//     {\n"
"//         float da, db;\n"
"//         \n"
"//         dbox(uv-vec2(.05,.3), vec2(1.6,.055), da);\n"
"//         da = mix(1.,da,smoothstep(125.,126.,iTime));\n"
"//         new.gba = mix(new.gba, mix(new.gba,c.xxx,.5), sm(da));\n"
"//         \n"
"//         // Wait, what?\n"
"//         dstring((uv-vec2(-.4,.3)), 28., .05, da);\n"
"//         \n"
"//         lfnoise(55.*uv, db);\n"
"//         stroke(db,0.535,db);\n"
"//         vec3 c1 = mix(mix(new.gba,c.yyy,.3), c.yyy, sm(db/50.));\n"
"//         \n"
"//         db = smoothstep(125.,126.,iTime);\n"
"//         da = mix(1., da, db);\n"
"//         new.gba = mix(new.gba, c1, sm(da));\n"
"//         \n"
"//         stroke(da-.01,.001,da);\n"
"//         new.gba = mix(new.gba, c.yyy, sm(da));\n"
"//     }\n"
"//     else\n"
"//     {\n"
"//         float da;\n"
"//         dstring(uv-vec2(-.55,0.), 27., .025, da);\n"
"//         da = mix(1., da, smoothstep(172.,172.5,iTime));\n"
"//         new.gba = mix(new.gba, c.yyy, smoothstep(172.,172.5,iTime));\n"
"//         new.gba = mix(new.gba, vec3(.9,.2,.03), sm(da));\n"
"//         stroke(da-.005, .001, da);\n"
"//         new.gba = mix(new.gba, c.xxx, sm(da));\n"
"//     }\n"
"    \n"
"    //FIXME: remove debug lines\n"
"//     vec2 ad = abs(mod(uv-.05,.02)-.01)-.001;\n"
"//     new.gba = mix(new.gba, c.yyx, sm(min(ad.x,ad.y)));\n"
"//     \n"
"//     ad = abs(mod(uv-.05,.1)-.05)-.001;\n"
"//     new.gba = mix(new.gba, c.yxy, sm(min(ad.x,ad.y)));\n"
"//     \n"
"//     ad = abs(uv)-.002;\n"
"//     new.gba = mix(new.gba, c.xxx, sm(min(ad.x,ad.y)));\n"
"    //FIXME remove until here\n"
"    \n"
"    \n"
"    // \n"
"    float dc;\n"
"    dbox(uv, .5*vec2(a,1.), dc);\n"
"    stroke(dc, .005, dc);\n"
"    new.gba = mix(new.gba, c.yyy, sm(dc));\n"
"    \n"
"    fragColor = vec4(new.gba, 1.);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\0";
const char *post_source = "/* Hardcyber - PC-64k-Intro by Team210 at Deadline 2k19\n"
" * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>\n"
" * \n"
" * This program is free software: you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation, either version 3 of the License, or\n"
" * (at your option) any later version.\n"
" * \n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" * \n"
" * You should have received a copy of the GNU General Public License\n"
" * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
" \n"
"#version 130\n\n"
"\n"
"uniform float iFSAA;\n"
"uniform vec2 iResolution;\n"
"uniform sampler2D iChannel0;\n"
"uniform float iTime;\n"
"\n"
"out vec4 gl_FragColor;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"float a = 1.0;\n"
"\n"
"float lscale, rscale;\n"
"float size;\n"
"\n"
"float nbeats;\n"
"float iScale;\n"
"\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void hash22(in vec2 x, out vec2 y);\n"
"float sm(float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"float dot2( in vec3 v ) { return dot(v,v); }\n"
"\n"
"// Adapted from https://www.shadertoy.com/view/4sXXRN\n"
"void dtriangle3(in vec3 p,  in vec3 v1, in vec3 v2, in vec3 v3, out float dst)\n"
"{\n"
"    vec3 v21 = v2 - v1; vec3 p1 = p - v1;\n"
"    vec3 v32 = v3 - v2; vec3 p2 = p - v2;\n"
"    vec3 v13 = v1 - v3; vec3 p3 = p - v3;\n"
"    vec3 nor = cross( v21, v13 );\n"
"\n"
"    dst = sqrt( (sign(dot(cross(v21,nor),p1)) + \n"
"                  sign(dot(cross(v32,nor),p2)) + \n"
"                  sign(dot(cross(v13,nor),p3))<2.0) \n"
"                  ?\n"
"                  min( min( \n"
"                  dot2(v21*clamp(dot(v21,p1)/dot2(v21),0.0,1.0)-p1), \n"
"                  dot2(v32*clamp(dot(v32,p2)/dot2(v32),0.0,1.0)-p2) ), \n"
"                  dot2(v13*clamp(dot(v13,p3)/dot2(v13),0.0,1.0)-p3) )\n"
"                  :\n"
"                  dot(nor,p1)*dot(nor,p1)/dot2(nor) );\n"
"}\n"
"\n"
"void rot3(in vec3 p, out mat3 rot);\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"mat3 R;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    float d;\n"
"    \n"
"	// Big red box    \n"
"    dbox3(x, .2*c.xxx, sdf.x);\n"
"    sdf.y = 1.;\n"
"    \n"
"    // Holes\n"
"    \n"
"    // 2 upper bar\n"
"    dbox3(x-.1*c.xyy, vec3(.02,.3,.12), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 right bar\n"
"    dbox3(x-.05*c.xyy-.1*c.yyx, vec3(.07,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 mid bar\n"
"    dbox3(x, vec3(.02,.3,.1), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 left bar\n"
"    dbox3(x+.05*c.xyy+.1*c.yyx, vec3(.07,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 2 dot\n"
"    dbox3(x+.1*c.xyy-.1*c.yyx, vec3(.02,.3,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 1 bar\n"
"    dbox3(x+.04*c.yyx, vec3(.3,.02,.08), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 1 dot\n"
"    dbox3(x-.1*c.yyx, vec3(.3,.02,.02), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"    \n"
"    // 0 big stripes\n"
"    vec3 y = vec3(x.x, abs(x.y), x.z);\n"
"    dbox3(y-.05*c.yxy, vec3(.1,.03,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"\n"
"	// 0 small stripes\n"
"    dbox3(y-.1*c.yxy-.06*c.xyy, vec3(.08,.021,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"\n"
"    // 0 upper/lower stripes\n"
"    vec3 z = vec3(abs(x.x), x.yz);\n"
"	dbox3(z-.119*c.xyy, vec3(.021,.08,.3), d);\n"
"    sdf.x = max(-d, sdf.x);\n"
"    sdf.y = mix(sdf.y, 2., step(d, sdf.x));\n"
"}\n"
"\n"
"void scene2(in vec3 x, out vec2 sdf)\n"
"{\n"
"    float v = 0., vn;\n"
"    vec2 vi = c.yy;\n"
"    dvoronoi(x.xy/size, v, vi, vn);\n"
"    vec3 y = vec3(x.xy-vi*size, x.z);\n"
"    vec2 yi = vi*size;\n"
"    \n"
"    float n = 0.;\n"
"    lfnoise(4.*(yi-.5*iTime), n);\n"
"    lfnoise(12.*vec2(n,1.)*yi-(.8+.2*n)*c.xy, n);\n"
"    n *= iScale;\n"
"    //sdf = vec2(length(y-.05*n*c.yyx)-.5*size, 1.);\n"
"//     sdf = vec2(length(y-.05*n*c.yyx)-mix(.05,1.,length(texture(iChannel0, yi/vec2(a,1.)).rgb)/sqrt(3.))*size, 1.);\n"
"    sdf = vec2(length(y-.05*n*c.yyx)-size*vn*mix(1.,4.,length(texture(iChannel0, yi/vec2(a,1.)).rgb)/sqrt(3.)), 1.);\n"
"}\n"
"\n"
"void normal2(in vec3 x, out vec3 n, in float dx)\n"
"{\n"
"    vec2 s, na;\n"
"    \n"
"    scene2(x,s);\n"
"    scene2(x+dx*c.xyy, na);\n"
"    n.x = na.x;\n"
"    scene2(x+dx*c.yxy, na);\n"
"    n.y = na.x;\n"
"    scene2(x+dx*c.yyx, na);\n"
"    n.z = na.x;\n"
"    n = normalize(n-s.x);\n"
"}\n"
"\n"
"void scene3(in vec3 x, out vec2 sdf)\n"
"{\n"
"    vec3 y = vec3(mod(x.xy,2.*size)-size, x.z);\n"
"    vec2 yi = x.xy-y.xy;\n"
"    float ss = mix(.0,.05,size/.01);\n"
"    \n"
"    vec2 p0 = .8*size*c.xx,\n"
"        p1 = .8*size*c.zx,\n"
"        p2 = .8*size*c.xz;\n"
"    \n"
"    vec2 ind;\n"
"    \n"
"    float y0, y1, y2;\n"
"    lfnoise(4.e1*(yi+p0-.5e-4*iTime), y0);\n"
"    lfnoise(12.e1*vec2(y0,1.)*(yi+p0)-1.e-4*(.8+.2*y0)*iTime*c.xy, y0);\n"
"    lfnoise(4.e1*(yi+p1-.5e-4*iTime), y1);\n"
"    lfnoise(12.e1*vec2(y1,1.)*(yi+p1)-1.e-4*(.8+.2*y1)*iTime*c.xy, y1);\n"
"    lfnoise(4.e1*(yi+p2-.5e-4*iTime), y2);\n"
"    lfnoise(12.e1*vec2(y2,1.)*(yi+p2)-1.e-4*(.8+.2*y2)*iTime*c.xy, y2);\n"
"    y0 *= ss;\n"
"    y1 *= ss;\n"
"    y2 *= ss;\n"
"    \n"
"    dtriangle3(y, vec3(p0,y0), vec3(p1,y1), vec3(p2,y2), sdf.x);\n"
"    \n"
"    float d;\n"
"    vec2 p3 = .8*size*c.zz,\n"
"        p4 = .8*size*c.xz,\n"
"        p5 = .8*size*c.zx;\n"
"    \n"
"    float y3, y4, y5;\n"
"    lfnoise(4.e1*(yi+p3-.5e-4*iTime), y3);\n"
"    lfnoise(12.e1*vec2(y3,1.)*(yi+p3)-1.e-4*(.8+.2*y3)*iTime*c.xy, y3);\n"
"    lfnoise(4.e1*(yi+p4-.5e-4*iTime), y4);\n"
"    lfnoise(12.e1*vec2(y4,1.)*(yi+p4)-1.e-4*(.8+.2*y4)*iTime*c.xy, y4);\n"
"    lfnoise(4.e1*(yi+p5-.5e-4*iTime), y5);\n"
"    lfnoise(12.e1*vec2(y5,1.)*(yi+p5)-1.e-4*(.8+.2*y5)*iTime*c.xy, y5);\n"
"    y3 *= ss;\n"
"    y4 *= ss;\n"
"    y5 *= ss;\n"
"    \n"
"    dtriangle3(y, vec3(p3,y3), vec3(p4,y4), vec3(p5,y5), d);\n"
"    sdf.x = min(sdf.x, d);\n"
"\n"
"    stroke(sdf.x, .1*size, sdf.x);\n"
"    sdf.y = 1.;\n"
"}\n"
"\n"
"void normal3(in vec3 x, out vec3 n, in float dx)\n"
"{\n"
"    vec2 s, na;\n"
"    \n"
"    scene3(x,s);\n"
"    scene3(x+dx*c.xyy, na);\n"
"    n.x = na.x;\n"
"    scene3(x+dx*c.yxy, na);\n"
"    n.y = na.x;\n"
"    scene3(x+dx*c.yyx, na);\n"
"    n.z = na.x;\n"
"    n = normalize(n-s.x);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"void mainImage( out vec4 fragColor, in vec2 fragCoord_ )\n"
"{\n"
"    vec2 fragCoord = fragCoord_;\n"
"    \n"
"    if(iTime < 159.5456 && iTime > 155.9092)\n"
"    {\n"
"        vec2 n;\n"
"        lfnoise(22.*fragCoord/iResolution-3.*iTime, n.x);\n"
"        lfnoise(22.*fragCoord/iResolution-3.*iTime-1337., n.y);\n"
"        fragCoord += 22.*n;\n"
"    }\n"
"    else if(iTime < 165. && iTime > 163.182)\n"
"    {\n"
"        vec2 n;\n"
"        lfnoise(22.*fragCoord/iResolution-3.*iTime, n.x);\n"
"        lfnoise(22.*fragCoord/iResolution-3.*iTime-1337., n.y);\n"
"        fragCoord += 22.*n;\n"
"    }\n"
"    \n"
"//     vec3 as = texture(iChannel0, fragCoord/iResolution).rgb;\n"
"//     vec2 nb;\n"
"//     lfnoise((as.xy+as.yz+as.xz), nb.x);\n"
"//     lfnoise((as.xy+as.yz+as.xz), nb.y);\n"
"//     fragCoord += 22.*(.1*as.r + .2*as.g + .3*as.b);\n"
"    \n"
"    float a = iResolution.x/iResolution.y;\n"
"    vec2 uv = fragCoord/iResolution.yy-0.5*vec2(a, 1.0);\n"
"    \n"
"    nbeats = mod(iTime, 60./29.);\n"
"    iScale = nbeats-30./29.;\n"
"    iScale = smoothstep(-5./29., 0., iScale)*(1.-smoothstep(0., 15./29., iScale));\n"
"    \n"
"    vec3 col = texture(iChannel0, fragCoord/iResolution).rgb;\n"
"    float delta = 0.;\n"
"//     vec2 n = c.yy;\n"
"    \n"
"    // Box\n"
"    rot3(vec3(-2.*pi/8.,2.*pi/8.,2.*pi/4.)-iTime*vec3(1.1,1.3,1.5), R);\n"
"    \n"
"    float d;\n"
"    vec2 s;\n"
"    vec3 o, r, u, t, ssize, dir, x, n;\n"
"    vec2 uv2 = 10.*(uv-vec2(-.45*a,.45));\n"
"    o = R * c.yyx;\n"
"	r = c.xyy; \n"
"	u = c.yxy;\n"
"	t = c.yyy; \n"
"    int N = 250,\n"
"        i;\n"
"    t = uv2.x * r + uv2.y * u;\n"
"    t = R * t;\n"
"    dir = normalize(t-o);\n"
"\n"
"    ssize = .2*c.xxx;\n"
"\n"
"	vec3 tlo = min((ssize-o)/dir,(-ssize-o)/dir); // Select 3 visible planes\n"
"    vec2 abxlo = abs(o.yz + tlo.x*dir.yz),\n"
"        abylo = abs(o.xz + tlo.y*dir.xz),\n"
"        abzlo = abs(o.xy + tlo.z*dir.xy);\n"
"\n"
"    vec4 dn = 100.*c.xyyy;\n"
"\n"
"    dn = mix(dn, vec4(tlo.x,c.xyy), float(all(lessThan(abxlo,ssize.yz)))*step(tlo.x,dn.x));\n"
"    dn = mix(dn, vec4(tlo.y,c.yxy), float(all(lessThan(abylo,ssize.xz)))*step(tlo.y,dn.x));\n"
"    dn = mix(dn, vec4(tlo.z,c.yyx), float(all(lessThan(abzlo,ssize.xy)))*step(tlo.z,dn.x));\n"
"    \n"
"    uv = (fragCoord)/iResolution.xy*vec2(a,1.);\n"
"    \n"
"    d = dn.r;\n"
"    \n"
"    float nan;\n"
"    lfnoise(iTime*c.xx, nan);\n"
"    nan += .5;\n"
"    if(nan > 0.) d = 3.;\n"
"    \n"
"    if(d<=2.)\n"
"    {\n"
"        x = o + d * dir;\n"
"        scene(x,s);\n"
"        \n"
"        if(s.x > 1.e-4)\n"
"        {\n"
"            for(i = 0; i<N; ++i)\n"
"            {\n"
"                x = o + d * dir;\n"
"                scene(x,s);\n"
"                if(s.x < 1.e-4)break;\n"
"                d += s.x;\n"
"            }\n"
"        }\n"
"        \n"
"        if(i<N)\n"
"        {\n"
"            normal(x,n, 5.e-4);\n"
"            \n"
"            if(s.y == 1.)\n"
"            {\n"
"                vec3 l = normalize(x+c.zzx*vec3(1.3,.9,1.2));\n"
"                col = vec3(0.81,0.15,0.18);\n"
"                col = .3*col\n"
"                    + .4*col * abs(dot(l,n))\n"
"                    + .6 * col * abs(pow(dot(reflect(-l,n),dir),2.));\n"
"            }\n"
"            else if(s.y == 2.)\n"
"            {\n"
"                vec3 l = normalize(x+c.zzx*vec3(1.3,.9,1.2));\n"
"                col = .7*c.xxx;\n"
"                col = .5*col\n"
"                    + .4*col * abs(dot(l,n))\n"
"                    + .8 * col * abs(pow(dot(reflect(-l,n),dir),2.));\n"
"            }\n"
"        }\n"
"        \n"
"        if(iTime < 0.) col = texture(iChannel0, fragCoord/iResolution).rgb;\n"
"    }\n"
"    else\n"
"    {\n"
"        iScale = nbeats-30./29.;\n"
"        iScale = smoothstep(-5./29., 0., iScale)*(1.-smoothstep(0./29., 35./29., iScale));\n"
"//         lscale = iScale;\n"
"//         lscale = smoothstep(0.,.5,clamp((iTime-6.),0.,1.))*(1.-smoothstep(0.,.5,clamp((iTime-13.),0.,1.)));\n"
"//         lscale += smoothstep(0.,.5,clamp((iTime-10.),0.,1.))*(1.-smoothstep(0.,.5,clamp((iTime-18.),0.,1.)));\n"
"//         rscale = smoothstep(167.,167.5,iTime)-smoothstep(172.,172.5,iTime);\n"
"        \n"
"//         rscale = iScale;\n"
"        rscale = 0.;\n"
"        lscale = 0.;\n"
"        size = mix(.005, .01, rscale);\n"
"        size = mix(0., size, max(rscale, lscale));\n"
"     \n"
"        if(lscale > 0.)\n"
"        {\n"
"            col = c.yyy;\n"
"            \n"
"            o = c.yyx+.5*vec3(cos(iTime), sin(iTime),0.);\n"
"            r = c.xyy;\n"
"            u = c.yxy;\n"
"            t = c.yyy;\n"
"            dir = c.yyy;\n"
"            n = c.yyy;\n"
"            x = c.yyy;\n"
"            N = 200;\n"
"            t = uv.x * r + uv.y * u;\n"
"            dir = normalize(t-o);\n"
"\n"
"            d = -(o.z-.05-.5*size)/dir.z;\n"
"            \n"
"            for(i = 0; i<N; ++i)\n"
"            {\n"
"                x = o + d * dir;\n"
"                scene2(x,s);\n"
"                if(s.x < 1.e-4)break;\n"
"                \n"
"                if(x.z<-.05-.5*size)\n"
"                {\n"
"                    col = c.yyy;\n"
"                    i = N;\n"
"                    break;\n"
"                }\n"
"                d += min(s.x,1.e-3);\n"
"                //d += s.x;\n"
"            }\n"
"            \n"
"            if(i < N)\n"
"            {\n"
"                normal2(x,n, 5.e-4);\n"
"                vec3 l = normalize(x+.5*n);\n"
"            \n"
"                if(s.y == 1.)\n"
"                {\n"
"                    float v, vn;\n"
"                    vec2 vi;\n"
"                    dvoronoi(x.xy/size, v, vi, vn);\n"
"                    vec3 y = vec3(x.xy-vi*size, x.z);\n"
"                    vec2 yi = vi*size;\n"
"                    \n"
"                    float bound = sqrt(iFSAA)-1.;\n"
"\n"
"                    for(float i = -.5*bound; i<=.5*bound; i+=1.)\n"
"                        for(float j=-.5*bound; j<=.5*bound; j+=1.)\n"
"                        {\n"
"                            col += texture(iChannel0, yi/vec2(a,1.)+vec2(i,j)*3./max(bound, 1.)/iResolution.xy).xyz;\n"
"                        }\n"
"                    col /= iFSAA;   \n"
"                    \n"
"                    col = .4*col\n"
"                        + .9*col * abs(dot(l,n))\n"
"                        + .6*col * pow(abs(dot(reflect(-l,n),dir)),3.);\n"
"                }\n"
"            }\n"
"            else col = c.yyy;\n"
"        }\n"
"        else if(rscale > 0.)\n"
"        {\n"
"            col = c.yyy;\n"
"            \n"
"            o = c.yyx+.5*vec3(-1., -1.,0.);\n"
"            r = c.xyy;\n"
"            u = c.yxy;\n"
"            t = c.yyy;\n"
"            dir = c.yyy;\n"
"            n = c.yyy;\n"
"            x = c.yyy;\n"
"            N = 300;\n"
"            t = uv.x * r + uv.y * u;\n"
"            dir = normalize(t-o);\n"
"\n"
"            d = -(o.z-.05-.5*size)/dir.z;\n"
"            \n"
"            for(i = 0; i<N; ++i)\n"
"            {\n"
"                x = o + d * dir;\n"
"                scene3(x,s);\n"
"                if(s.x < 1.e-4)break;\n"
"                \n"
"                if(x.z<-.05-.5*size)\n"
"                {\n"
"                    col = c.yyy;\n"
"                    i = N;\n"
"                    break;\n"
"                }\n"
"                d += min(s.x,1.e-3);\n"
"                //d += s.x;\n"
"            }\n"
"            \n"
"            if(i < N)\n"
"            {\n"
"                normal3(x,n, 5.e-4);\n"
"                vec3 l = normalize(x+.5*n);\n"
"            \n"
"                if(s.y == 1.)\n"
"                {\n"
"                    vec3 y = vec3(mod(x.xy,size)-.5*size, x.z);\n"
"                    vec2 yi = x.xy-y.xy;\n"
"                    \n"
"                    col = texture(iChannel0, yi/vec2(a,1.)).rgb;\n"
"                    \n"
"//                     col = .7*c.xxy;\n"
"                    \n"
"                    col = .4*col\n"
"                        + .9*col * abs(dot(l,n))\n"
"                        + .6*col * pow(abs(dot(reflect(-l,n),dir)),3.);\n"
"                    \n"
"                }\n"
"            }\n"
"            else col = c.yyy;\n"
"        }\n"
"    }\n"
"    \n"
"    // Scan lines\n"
"    col += vec3(0., 0.05, 0.1)*sin(uv.y*1050.+ 5.*iTime);\n"
"    \n"
"    fragColor = vec4(clamp(col,0.,1.),1.0);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    mainImage(gl_FragColor, gl_FragCoord.xy);\n"
"}\n"
"\0";
const char *deadline_source = "#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void hash11(in float p, out float d);\n"
"void hash12(in vec2 p, out float d);\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void ddeadline(in vec2 x, out float ret);\n"
"void zextrude(in float z, in float d2d, in float h, out float d);\n"
"\n"
"vec2 pdec;\n"
"void ddecorations(in vec2 x, in float decs, out float d)\n"
"{\n"
"    float r, v, vz;\n"
"    vec2 y, yi;\n"
"    \n"
"    dvoronoi(x/decs, v, yi, vz);\n"
"    y = x-yi*decs;\n"
" \n"
"    hash12(yi*decs, r);\n"
"    if(r < .5)\n"
"    {\n"
"        dbox(y, vz*decs/sqrt(2.)*c.xx, d);\n"
"    }\n"
"    else\n"
"    {\n"
"        hash11(r, r);\n"
"        d = length(y)-vz*decs;\n"
"    }\n"
"    \n"
"    pdec = yi/decs;\n"
"}\n"
"\n"
"float m;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    if(iTime < 8.)\n"
"    {\n"
"        ddeadline(x.xy, sdf.x);\n"
"        zextrude(x.z, -sdf.x, mix(.0,.2,clamp(iTime-2.,0.,1.)*(1.-clamp(iTime-7.,0.,1.))), sdf.x);\n"
"        sdf.x = min(sdf.x, x.z);\n"
"        \n"
"        sdf.y = 1.;\n"
"    }\n"
"    else\n"
"    {\n"
"        sdf.x = x.z;\n"
"        sdf.y = 1.;\n"
"    }\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"const vec3 orange =vec3(0.20,0.60,0.86),\n"
"    redorange = vec3(0.27,0.70,0.62);\n"
"\n"
"void modgradient(in vec2 x, in float decs, inout vec3 col)\n"
"{\n"
"    float y = mod(x.y, decs)-.5*decs;\n"
"    \n"
"    col = mix(orange, redorange, 2.*abs(y)/decs);\n"
"}\n"
"\n"
"float ddl;\n"
"void colorize(in vec2 uv, out vec3 col)\n"
"{\n"
"    vec3 c1 = col;\n"
"    float d;\n"
"    \n"
"    // Background geraffel\n"
"    for(float decs = .05; decs <= 1.; decs += .05)\n"
"    {\n"
"        modgradient(uv, decs, c1);\n"
"        \n"
"        ddecorations(uv-1337.-12.*decs*c.yx, decs, d);\n"
"        \n"
"        float ma;\n"
"        lfnoise((1.+5.*decs)*uv-1337.-12.*decs*c.yx-clamp(iTime/3.,0.,1.)*iTime*c.yx, ma);\n"
"        col = mix(col, mix(col,c1,mix(.6,.1,.8+.2*ma)* mix(1., 0., clamp(length(uv),0.,1.))), sm(d));\n"
"        stroke(d, .001, d);\n"
"        col = mix(col, 1.4*col, mix(0.,sm(d-.01),mix(0.,.5+.5*ma,clamp(iTime-10.,0.,1.))));\n"
"        col = mix(col, mix(orange,c.xxx,decs), sm(d));\n"
"    }\n"
"    \n"
"    col = mix(col, c.yyy, .2);\n"
"\n"
"    if(iTime < 8.)\n"
"    {\n"
"        ddeadline(uv, d);\n"
"        ddl = d;\n"
"        \n"
"        c1 = mix(col,mix(col,mix(3.5,5.5,.5+.5*sin(6.*iTime))*vec3(0.27,0.36,0.48),.5), sm(ddl/150.));\n"
"        \n"
"        c1 = mix(c1, mix(col,1.3*vec3(0.27,0.36,0.48),.8), sm(d+.002));\n"
"        stroke(d,.002, d);\n"
"        c1 = mix(c1, 2.5*vec3(0.27,0.36,0.48), sm(d));\n"
"        \n"
"        col = mix(col, c1, clamp((iTime-2.),0.,1.)*(1.-clamp(iTime-7.,0.,1.)));\n"
"    }\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    \n"
"    vec3 col = c.xxx,\n"
"        o = mix((vec3(uv,1.)),c.yyx+.4*c.yzy,clamp(iTime-1.,0.,1.)),\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x;\n"
"    int N = 150,\n"
"        i;\n"
"    float d;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = mix(c.yyz,normalize(t-o),clamp(iTime-1.,0.,1.));\n"
"\n"
"    vec3 c0, c1;\n"
"    colorize(uv,c0);\n"
"    \n"
"    d = -(o.z-mix(0.,.2,step(2.,iTime)))/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(x.z<0.)\n"
"        {\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += s.x;\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = x+c.yyx;\n"
"        normal(x,n, 2.e-6);\n"
"        colorize(x.xy, col);\n"
"        col = .1*col \n"
"            + .4*col*dot(l, n)\n"
"            + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"    }\n"
"    \n"
"    col = 2.*col*col;\n"
"    col = mix(c0, col, clamp(iTime,0.,1.));\n"
"    \n"
"    col = mix(col, vec3(0.18,0.24,0.31), clamp(iTime-19.,0.,1.));\n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\n"
"\0";
const char *hydrant_source = "#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.,0.,-1.);\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void mfnoise(in vec2 x, in float d, in float b, in float e, out float n);\n"
"void hash11(in float p, out float d);\n"
"void hash12(in vec2 p, out float d);\n"
"void hash21(in float p, out vec2 d);\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void hash31(in float p, out vec3 d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void drhomboid(in vec2 x, in vec2 b, in float tilt, out float dst);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void zextrude(in float z, in float d2d, in float h, out float d);\n"
"\n"
"void dhydrantradius(in float lxy, in float z, in float phi, out float r)\n"
"{\n"
"    const float dx = 2.e-2,\n"
"        rfoot = .3,\n"
"        rpipe = .5,\n"
"        rtop = .01;\n"
"    \n"
"    float y = abs(z)-.4;\n"
"    \n"
"    // sides\n"
"    r = rfoot*step(y,6.*dx)*step(0.,y);\n"
"    r += .1*rfoot*smoothstep(.3*dx, .7*dx, y)*(1.-smoothstep(5.3*dx,5.7*dx, y));\n"
"    r += .1*rfoot*smoothstep(1.3*dx, 1.7*dx, y)*(1.-smoothstep(4.3*dx,4.7*dx, y));\n"
"    r += .6*rfoot*step(y,0.);\n"
"    \n"
"    // center\n"
"    y = z+.2;\n"
"    r += .1*rfoot*smoothstep(.3*dx, .7*dx, y)*(1.-smoothstep(5.3*dx,5.7*dx, y));\n"
"    r += .1*rfoot*smoothstep(1.3*dx, 1.7*dx, y)*(1.-smoothstep(4.3*dx,4.7*dx, y));\n"
"    \n"
"    // cap\n"
"    float phidep = clamp(-.5+2.*abs(cos(2.*pi*phi)),0.,1.);\n"
"    r += step(.52,z)*mix(.8*rfoot*(1.+.05*phidep), rtop*(1.+.05*phidep), smoothstep(0.,24.*dx, z - .55));\n"
"    r *= step(z,.9);\n"
"    \n"
"    // cap decoration\n"
"    r += .2*rfoot*step(.9,z)*step(z,.9+2.*dx);\n"
"    r += .3*rfoot*smoothstep(9.,10., z)*(1.-smoothstep(10., 11., z));\n"
"    r += .1*rfoot*smoothstep(.3*dx, .7*dx, z-9.)*(1.-smoothstep(1.3*dx, 1.7*dx, z-9.));\n"
"    r = lxy - r;\n"
"}\n"
"\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{    \n"
"    vec3 y = 2.*x;\n"
"    dhydrantradius(length(y.xy), y.z, atan(y.y, y.x), sdf.x);\n"
"    \n"
"    sdf.x /= 10.;\n"
"    \n"
"    float rarm = .05;\n"
"    rarm -= .01*smoothstep(.05, .07, abs(x.x)-.05);\n"
"    rarm -= .01*smoothstep(.05, .07, abs(x.x)-.1);\n"
"    rarm -= .02*step(.08, abs(x.x)-.05)*step(abs(x.x)-.05, .09);\n"
"    rarm -= .02*step(.08, abs(x.x)-.1)*step(abs(x.x)-.1, .09);\n"
"    rarm += .03*step(.17, abs(x.x))*step(abs(x.x),.19);\n"
"    sdf.x = min(sdf.x, length(x.yz-.05*c.yx)-rarm*(step(abs(x.x),.2)));\n"
"    \n"
"    rarm = .05;\n"
"    rarm -= .01*smoothstep(.05, .07, abs(x.y)-.05);\n"
"    rarm -= .01*smoothstep(.05, .07, abs(x.y)-.1);\n"
"    rarm -= .02*step(.08, abs(x.y)-.05)*step(abs(x.y)-.05, .09);\n"
"    rarm -= .02*step(.08, abs(x.y)-.1)*step(abs(x.y)-.1, .09);\n"
"    rarm += .03*step(.17, abs(x.y))*step(abs(x.y),.2);\n"
"    sdf.x = min(sdf.x, .1*(length(x.xz-.05*c.yx)-rarm*step(abs(x.y),.2)));\n"
"    \n"
"    sdf.y = 0.;\n"
"    \n"
"    add(sdf, vec2(x.z+.4,1.), sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void dcircle(in vec2 x, out float d)\n"
"{\n"
"    d = length(x)-1.;\n"
"}\n"
"\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"void dspacepigs(in vec2 x, out float d);\n"
"\n"
"const vec3 orange = 2.*vec3(0.99,0.34,0.39),\n"
"    redorange = vec3(0.97,0.60,0.33);\n"
"void ddecorations(in vec2 x, in float decs, out float d)\n"
"{\n"
"    float r, v, vz;\n"
"    vec2 y, yi;\n"
"    \n"
"    dvoronoi(x/decs, v, yi, vz);\n"
"    y = x-yi*decs;\n"
" \n"
"//     hash12(yi*decs, r);\n"
"//     if(r < .5)\n"
"//     {\n"
"//         dbox(y, vz*decs/sqrt(2.)*c.xx, d);\n"
"//     }\n"
"//     else\n"
"//     {\n"
"//         hash11(r, r);\n"
"//         d = length(y)-vz*decs;\n"
"//     }\n"
"    dspacepigs(y/decs*2.5, d);\n"
"    d *= -decs/2.5;\n"
"}\n"
"\n"
"void modgradient(in vec2 x, in float decs, inout vec3 col)\n"
"{\n"
"    float y = mod(x.y, decs)-.5*decs;\n"
"    \n"
"    col = mix(orange, redorange, 2.*abs(y)/decs);\n"
"}\n"
"\n"
"float ddl;\n"
"void colorize(in vec2 uv, out vec3 col)\n"
"{\n"
"    vec3 c1 = col;\n"
"    float d;\n"
"    \n"
"    // Background geraffel\n"
"    for(float decs = .4; decs <= 1.5; decs += .3)\n"
"    {\n"
"        modgradient(uv, decs, c1);\n"
"        \n"
"        ddecorations(uv-1337.-12.*decs*c.yx, decs, d);\n"
"        \n"
"        float m;\n"
"        lfnoise((1.+5.*decs)*uv-1337.-12.*decs*c.yx, m);\n"
"        \n"
"        col = mix(col, mix(col,c1,mix(.6,.1,.8+.0*m)),.8*decs*sm(d));// mix(1., 0., clamp(.5*length(uv),0.,1.))), sm(d));\n"
"        stroke(d, .001, d);\n"
"        col = mix(col, mix(orange,c.xxx,decs), sm(d));\n"
"    }\n"
"    \n"
"    col = mix(col, c.yyy, .2);\n"
"}\n"
"\n"
"void analytical_box(in vec3 o, in vec3 dir, in vec3 size, out float d);\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    \n"
"    vec3 col = c.xxx,\n"
"        o = c.yyx+1.4*c.yzy+.3*vec3(cos(iTime), sin(iTime), 0.),\n"
"        r = vec3(sin(iTime), cos(iTime), 0.),\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x;\n"
"    int N = 250,\n"
"        i;\n"
"    float d;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"\n"
"    vec3 c0, c1;\n"
"    colorize(uv,c0);\n"
"    \n"
"    analytical_box(o-.25*c.yyx, dir, vec3(.2,.2,.5),d);\n"
"    if(d > 4.)\n"
"    d = -o.z/dir.z;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(x.y>.5)\n"
"        {\n"
"            d = -(o.z+.4)/dir.z;\n"
"            x = o + d * dir;\n"
"            scene(x,s);\n"
"            break;\n"
"        }\n"
"        d += s.x;\n"
"\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = 2.*normalize(x+2.*c.xxx);//x+c.yyx;\n"
"        normal(x,n, 2.e-3);\n"
"        \n"
"        if(s.y == 0.)\n"
"        {\n"
"            col = vec3(0.47,0.21,0.22);\n"
"            \n"
"            float na;\n"
"            mfnoise(vec2(12.*length(x),x.z)+vec2(x.z,atan(x.y,x.x)),5.,500., .45, na);\n"
"            col = mix(col,.1*c.xxx, sm(na+.3));\n"
"            col = mix(col, .5*col, .5+.5*na);\n"
"            \n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + .7*col*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"        }\n"
"        else if(s.y == 1.)\n"
"        {\n"
"            colorize(x.xy, col);\n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"    }\n"
"\n"
"    col = 2.*col*col;\n"
"//     col = mix(col, c0, clamp(iTime/2.,0.,1.));\n"
"//     col = mix(col, c.yyy, clamp(iTime-9.,0.,1.));\n"
"\n"
"//     dhydrantradius(abs(uv.y), uv.x+.2, 0., d);\n"
"//     col = mix(col, c.yyy, sm(abs(d)-.001));\n"
"\n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\n"
"\0";
const char *watercubes_source = "uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"// Global constants\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"vec3 color1, color2;\n"
"\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void hash33(in vec3 p3, out vec3 d);\n"
"void dvoronoi3(in vec3 x, out float d, out vec3 p, out float control_distance);\n"
"void smoothmin(in float a, in float b, in float k, out float dst);\n"
"void dsmoothvoronoi3(in vec3 x, out float d, out vec3 p, out float control_distance);\n"
"\n"
"mat3 gR;\n"
"void rot3(in vec3 p, out mat3 rot);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"void dstar(in vec2 x, in float N, in vec2 R, out float dst);\n"
"void smoothmax(in float a, in float b, in float k, out float res);\n"
"void dstar3(in vec3 x, in float N, in vec2 R, out float dst);\n"
"\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    if(length(x) > .5) sdf = vec2(length(x)-.5,-1.);\n"
"    x = gR * x;\n"
"    vec3 yi;\n"
"    float vi, \n"
"        vip, \n"
"        rel = 8.,\n"
"        db = length(x)-.4,\n"
"        dc;\n"
"    dbox3(x,.2,dc);\n"
"    db = mix(db, dc, clamp(iTime-5., 0., 1.));\n"
"    dstar3(x, 6., vec2(.2,.5), dc);\n"
"    db = mix(db, dc, clamp(iTime-10., 0.,1.));\n"
"//     db = mix(db, dc, .6+.6*sin(iTime));\n"
"    dsmoothvoronoi3(rel*x, vi, yi, vip);\n"
"    sdf = vec2(abs(vi/rel)-.0001, 0.);\n"
"    sdf.x = max(sdf.x, db);\n"
"    add(sdf, vec2(abs(db+.0002)-.0001, 1.), sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void colorize(in vec2 uv, out vec3 col)\n"
"{\n"
"    col = mix(color2, c.yyy, length(uv));\n"
"    \n"
"    vec2 s;\n"
"    scene(vec3(uv,0.), s);\n"
"    \n"
"    float v, vip, res = mix(12.,100., s.x);\n"
"    vec2 vi;\n"
"    dvoronoi(res*uv, v, vi, vip);\n"
"    float d = abs(v/res)-mix(.002,.0001, s.x);\n"
"    col = mix(col, 4.*col,sm(-v/res+.01));\n"
"    col = mix(col, mix(4.*color2, c.yyy, 2.*s.x), sm(d));\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    \n"
"    rot3(vec3(1.1,1.3,1.5)*iTime, gR);\n"
"    color1 = mix(vec3(0.47,0.21,0.22), vec3(0.17,0.24,0.30), clamp(iTime-5.,0.,1.));\n"
"    color1 = mix(color1, vec3(0.52,0.85,0.31), clamp(iTime-10., 0., 1.));\n"
"    color2 = mix(vec3(0.22,0.21,0.47), .3*vec3(1.00,0.59,0.22), clamp(iTime-5.,0.,1.));\n"
"    color2 = mix(color2, .15\n"
"    *c.xxx, clamp(iTime-10., 0., 1.));\n"
"    \n"
"    vec3 col = c.xxx,\n"
"        o = c.yyx,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x,\n"
"        c1,\n"
"        o0 = o;\n"
"    int N = 150,\n"
"        i;\n"
"        \n"
"    float d = .5;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(d > length(.6+.2*c.xx))\n"
"        {\n"
"            i = N;\n"
"            break;\n"
"        }\n"
"        d += s.x;\n"
"\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = 2.*normalize(x+2.*c.xxx);//x+c.yyx;\n"
"//         vec3 l = x + .3*(o-x);\n"
"        normal(x,n, 2.e-3);\n"
"        \n"
"        if(s.y == 0.)\n"
"        {\n"
"            col = color1;\n"
"            \n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + .7*col*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"        }\n"
"        else if(s.y == 1.)\n"
"        {\n"
"            col = color2;\n"
"            \n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"        }\n"
"        \n"
"        for(float k = .5; k < .9; k += .2)\n"
"        {\n"
"            o = x;\n"
"            d = 1.e-3;\n"
"            dir = refract(dir, n, .99);\n"
"            \n"
"            for(i = 0; i<N; ++i)\n"
"            {\n"
"                x = o + d * dir;\n"
"                scene(x,s);\n"
"                if(s.x < 1.e-5)break;\n"
"                if(d > length(o0)+.4001)\n"
"                {\n"
"                    i = N;\n"
"                    break;\n"
"                }\n"
"                d += s.x;\n"
"\n"
"            }\n"
"            \n"
"            if(i < N)\n"
"            {\n"
"                vec3 l = 2.*normalize(x+2.*c.xxx);//x+c.yyx;\n"
"//                 vec3 l = x + .3*(o-x);\n"
"                normal(x,n, 2.e-3);\n"
"                \n"
"                if(s.y == 0.)\n"
"                {\n"
"                    c1 = color1;\n"
"                    \n"
"                    c1 = .3*c1 \n"
"                        + .5*c1*dot(-l, n)\n"
"                        + .7*c1*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"                        \n"
"                    c1 = mix(c1, c.xxx, smoothstep(0.458, .602, 1.-abs(dot(n, c.yyz))));\n"
"                }\n"
"                else if(s.y == 1.)\n"
"                {\n"
"                    c1 = color2;\n"
"                    \n"
"                    c1 = .1*c1 \n"
"                        + .1*c1*dot(l, n)\n"
"                        + .6*c1*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"                }\n"
"                else c1 = c.yyx;\n"
"                \n"
"                col = mix(c1, col, k);\n"
"            }\n"
"            else colorize(uv,col);\n"
"        }\n"
"    }\n"
"    else colorize(uv,col);\n"
"    \n"
"    col = 2.*col*col;\n"
"    \n"
"    \n"
"//     col = mix(col, c0, clamp(iTime/2.,0.,1.));\n"
"//     col = mix(col, c.yyy, clamp(iTime-9.,0.,1.));\n"
"\n"
"//     dhydrantradius(abs(uv.y), uv.x+.2, 0., d);\n"
"//     col = mix(col, c.yyy, sm(abs(d)-.001));\n"
"\n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\0";
const char *glitchcity_source = "#version 130\n\n"
"\n"
"out vec4 gl_FragColor;\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"vec3 color1 =vec3(0.02,0.08,0.18),\n"
"    color2 = 2.*vec3(0.08,0.08,0.24);\n"
"\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void hash12(in vec2 p, out float d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"\n"
"float h;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    x.x += .1*iTime;\n"
"    \n"
"    vec2 vi;\n"
"    float v, vip, res = 15., d;\n"
"    dvoronoi(res*x.xz, v, vi, vip);\n"
"    vip /= res;\n"
"    vi /= res;\n"
"    v /= res;\n"
"    \n"
"    sdf = vec2(x.y,0.);\n"
"    \n"
"    if(vi.y < .5)\n"
"    {\n"
"        hash12(vi, h);\n"
"        vec2 cs = vec2(cos(2.*pi*h), sin(2.*pi*h));\n"
"        mat2 R = mat2(cs.x, cs.y, -cs.y, cs.x);\n"
"        vec3 y = vec3(x.x-vi.x, x.y, x.z-vi.y);\n"
"        y.xz = R * y.xz;\n"
"        dbox3(y, vip/sqrt(2.)*c.xyx+(.1+.05*h)*c.yxy, d);\n"
"        add(sdf, vec2(d, 1.), sdf);\n"
"    }\n"
"    sdf.x -= .003;\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void colorize(in vec2 uv, out vec3 col)\n"
"{\n"
"    col = c.yyy;\n"
"}\n"
"\n"
"void housetexture(in vec2 uv, out vec3 col)\n"
"{\n"
"    uv.x += .1*iTime;\n"
"    float dsta = .002;\n"
"    col = mix(.05*color1, 4.*color2, sm(4.*(abs(mod(uv.y, dsta)-.5*dsta)-.25*dsta)));\n"
"    \n"
"    vec2 x = mod(uv, dsta)-.5*dsta,\n"
"        xi = (uv-x)/dsta;\n"
"    float f;\n"
"    hash12(xi,f);\n"
"    if(f < .3)    \n"
"    {\n"
"        col = mix(col, mix(4.*col,c.xxx,.5), sm(min(abs(x.x), abs(x.y))-.25*dsta));\n"
"    }\n"
"}\n"
"\n"
"void palette2(in float scale, out vec3 col)\n"
"{\n"
"    const int N = 5;\n"
"    const vec3 colors[N] = vec3[N](\n"
"            vec3(0.98,0.80,1.00),\n"
"            vec3(0.52,1.00,0.42),\n"
"            vec3(0.45,0.99,0.96),\n"
"            vec3(1.00,0.09,0.31),\n"
"            vec3(1.00,1.00,0.43)\n"
"    );\n"
"	float index = floor(scale*float(N)), \n"
"        remainder = scale*float(N)-index;\n"
"    col = mix(colors[int(index)],colors[int(index)+1], remainder);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    \n"
"    if(uv.y>.16)\n"
"    {\n"
"        gl_FragColor = vec4(mix(vec3(0.10,0.17,0.33),c.yyy,clamp((uv.y-.16)/(.5-.16),0.,1.)),1.);\n"
"        return;\n"
"    }\n"
"    \n"
"    vec3 col = c.xxx,\n"
"        o = c.yyx+.2*c.yxy,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x,\n"
"        c1,\n"
"        o0 = o;\n"
"    int N = 350,\n"
"        i;\n"
"        \n"
"    float d;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"    d = -(o.y-.15)/dir.y;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-5)break;\n"
"        if(x.y > .15)\n"
"        {\n"
"            gl_FragColor = c.yyyx;\n"
"            return;\n"
"        }\n"
"        d += min(s.x,2.e-3);\n"
"    }\n"
"    \n"
"    float d0 = d;\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        vec3 l = x+c.yxy+.5*c.yyx;\n"
"        normal(x,n, 2.e-5);\n"
"        if(s.y == 0.)\n"
"        {\n"
"            col = color1;\n"
"            \n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + .7*col*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"            \n"
"            {\n"
"                o = x;\n"
"                d = 1.e-3;\n"
"                dir = reflect(dir, n);\n"
"                \n"
"                for(i = 0; i<N; ++i)\n"
"                {\n"
"                    x = o + d * dir;\n"
"                    scene(x,s);\n"
"                    if(s.x < 1.e-5)break;\n"
"                    if(x.y > .15)\n"
"                    {\n"
"                        gl_FragColor = c.yyyx;\n"
"                        return;\n"
"                    }\n"
"                    d += min(s.x,5.e-3);\n"
"                }\n"
"                \n"
"                if(i < N)\n"
"                {\n"
"                    vec3 l = x+c.yxy;\n"
"                    normal(x,n, 2.e-4);\n"
"                    \n"
"                    if(s.y == 0.)\n"
"                    {\n"
"                        c1 = color1;\n"
"                        \n"
"                        c1 = .3*c1 \n"
"                            + .5*c1*dot(-l, n)\n"
"                            + .7*c1*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"                    }\n"
"                    else if(s.y == 1.)\n"
"                    {\n"
"                        housetexture(x.xy, c1);\n"
"                        \n"
"                        c1 = .1*c1 \n"
"                            + .1*c1*dot(l, n)\n"
"                            + .6*c1*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"                    }\n"
"                    else c1 = c.yyx;\n"
"                    \n"
"                    col = mix(c1, col, .5);\n"
"                }\n"
"                else colorize(uv,col);\n"
"            }\n"
"        }\n"
"        else if(s.y == 1.)\n"
"        {\n"
"            housetexture(x.xy, col);\n"
"            \n"
"            col = .1*col \n"
"                + .1*col*dot(l, n)\n"
"                + .6*col*pow(abs(dot(reflect(-l,n),dir)),2.);\n"
"                \n"
"            col = mix(col, c.xxx, smoothstep(.63, 1.2, 1.-abs(dot(n, 3.*c.xyy))));\n"
"            col = mix(col, c.xxx, smoothstep(.63, 1.2, 1.-abs(dot(n, 3.*c.zyy))));\n"
"            \n"
"        }\n"
"    }\n"
"    else colorize(uv,col);\n"
"    \n"
"    d = d0;\n"
"    float ha = mod(abs(x.y)-mix(-1.,1.,h)*iTime+12.*h,.15);\n"
"    palette2(fract(h), c1);\n"
"    col = mix(col,1.15*c1, smoothstep(-.2,1.,smoothstep(.1,1.3,(1.-8.*ha)))); \n"
"    palette2(fract(h+13.37e-3), c1);\n"
"    col = mix(col,1.65*c1*c1, smoothstep(-.2,1.,smoothstep(.1,1.3,(1.-26.*ha)))); \n"
"    \n"
"    col = 2.*col*col;\n"
"    col = mix(col,c.yyy, smoothstep(0.,2.,d));\n"
"    \n"
"    col = clamp(col, 0.,1.);\n"
"    col = mix(col, c.yyy, .3);\n"
"    col = mix(col, vec3(0.10,0.17,0.33), smoothstep(.1,1.3,d));\n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\0";
const char *greetings_source = "uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"// Global constants\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void dhexagonpattern(in vec2 p, out float d, out vec2 ind);\n"
"\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dlinesegment(in vec2 x, in vec2 p1, in vec2 p2, out float d);\n"
"void stroke(in float d0, in float s, out float d);\n"
"void addwindow(in vec2 uv, inout vec3 col, in vec2 dimensions);\n"
"void dpolygon(in vec2 x, in float N, out float d);\n"
"void dmercury(in vec2 x, out float d);\n"
"void dcircle(in vec2 x, out float d);\n"
"void dtriangle(in vec2 p, in vec2 p0, in vec2 p1, in vec2 p2, out float dst);\n"
"void rot(in float phi, out mat2 m);\n"
"void dschnappsgirls(in vec2 x, out float d);\n"
"void dhaujobb(in vec2 x, out float d);\n"
"void dkewlers(in vec2 x, out float d);\n"
"void dfarbrausch(in vec2 x, out float d);\n"
"void d5711(in vec2 x, out float ret);\n"
"\n"
"void main()\n"
"{\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        hind;\n"
"    vec3 col = c.yyy,\n"
"        col1 = vec3(0.00,0.42,0.84); // blu\n"
"    float h,\n"
"        h0,\n"
"        res = 34.;\n"
"    \n"
"    col1 = mix(col1, vec3(0.91,0.30,0.24), clamp(iTime-4., 0., 1.)); // red\n"
"    col1 = mix(col1, vec3(0.44,0.65,0.35), clamp(iTime-9.,0.,1.)); // green\n"
"    col1 = mix(col1, vec3(0.82,0.14,0.34), clamp(iTime-14.,0.,1.)); // pink\n"
"    col1 = mix(col1, vec3(0.92,0.76,0.20), clamp(iTime-19.,0.,1.)); // orange\n"
"    col1 = mix(col1, .5*c.xxx, clamp(iTime-24.,0.,1.)); // grayscale\n"
"    \n"
"    dhexagonpattern(res*uv, h, hind);\n"
"    h /= res;\n"
"    h0 = h;\n"
"    hind /= res;\n"
"    h = -abs(h)+.005;\n"
"    col = mix(col, col1, sm(h));\n"
"    h = abs(h+.005)-.0015;\n"
"    col = mix(col, 2.*col, sm(h));\n"
"    \n"
"    float n;\n"
"    lfnoise(res*hind-iTime, n);\n"
"    col = mix(c.yyy, col, (.5+.5*n)*(1.-2.*abs(uv.y)));\n"
"    \n"
"    col = mix(col, 2.*col1, sm(abs(h0)-.001*(.5+.5*n)));\n"
"    \n"
"    col = 1.4*col;\n"
"    \n"
"    addwindow(uv, col, vec2(.6,.4));\n"
"    \n"
"    float d, da;\n"
"    if(iTime < 4.) dmercury(5.*uv, d);\n"
"    else if(iTime < 9.)\n"
"    {\n"
"        dmercury(5.*uv, d);\n"
"        dschnappsgirls(5.*uv, da);\n"
"        d = mix(d, da, clamp(iTime-4., 0., 1.));\n"
"    }\n"
"    else if(iTime < 14.)\n"
"    {\n"
"        dschnappsgirls(5.*uv, d);\n"
"        dhaujobb(5.*uv, da);\n"
"        d = mix(d, da, clamp(iTime-9., 0., 1.));\n"
"    }\n"
"    else if(iTime < 19.)\n"
"    {\n"
"        dhaujobb(5.*uv, d);\n"
"        dkewlers(5.*uv, da);\n"
"        d = mix(d, da, clamp(iTime-14., 0., 1.));\n"
"    }\n"
"    else if(iTime < 24.)\n"
"    {\n"
"        dkewlers(5.*uv, d);\n"
"        dfarbrausch(5.*uv, da);\n"
"        d = mix(d, da, clamp(iTime-19., 0., 1.));\n"
"    }\n"
"    else if(iTime < 29.)\n"
"    {\n"
"        dfarbrausch(5.*uv, d);\n"
"        d5711(5.*uv, da);\n"
"        d = mix(d, da, clamp(iTime-24., 0., 1.));\n"
"    }\n"
"    d /= 5.;\n"
"    col = mix(col, 1.9*col1, sm(d));\n"
"    col = mix(col, mix(col, 3.*col1, .5+.5*sin(iTime)), sm((abs(d-.01)-.001)/22.));\n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\0";
const char *fractal_source = "#version 130\n\n"
"\n"
"uniform float iTime;\n"
"uniform vec2 iResolution;\n"
"\n"
"uniform float iFader0;\n"
"uniform float iFader1;\n"
"uniform float iFader2;\n"
"uniform float iFader3;\n"
"uniform float iFader4;\n"
"uniform float iFader5;\n"
"uniform float iFader6;\n"
"uniform float iFader7;\n"
"\n"
"// Global constants\n"
"const float pi = acos(-1.);\n"
"const vec3 c = vec3(1.0, 0.0, -1.0);\n"
"float a = 1.0;\n"
"\n"
"void rand(in vec2 x, out float n);\n"
"void lfnoise(in vec2 t, out float n);\n"
"void hash22(in vec2 p, out vec2 d);\n"
"void dvoronoi(in vec2 x, out float d, out vec2 p, out float control_distance);\n"
"void add(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void sub(in vec2 sda, in vec2 sdb, out vec2 sdf);\n"
"void zextrude(in float z, in float d2d, in float h, out float d);\n"
"void dbox3(in vec3 x, in vec3 b, out float d);\n"
"void rot3(in vec3 p, out mat3 rot);\n"
"void dbox(in vec2 x, in vec2 b, out float d);\n"
"void dstar(in vec2 x, in float N, in vec2 R, out float dst);\n"
"void doctahedron(in vec3 x, in float h, in float w, out float d);\n"
"\n"
"mat3 gR;\n"
"vec2 ind = c.yy;\n"
"void scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    vec3 y = x;\n"
"    x.xy += vec2(cos(.3*iTime), sin(.3*iTime));\n"
"    \n"
"    sdf.x = x.z;\n"
"    sdf.y = 0.;\n"
"    \n"
"    float db = abs(length(y-.1*c.yyx)-.2), \n"
"        dc;\n"
"    dbox3(gR * (y-.1*c.yyx), .2*c.xxx, dc);\n"
"    db = mix(db, abs(dc)-.001, clamp(iTime-5.,0.,1.));\n"
"    doctahedron(gR * (y-.1*c.yyx),.4,.4, dc);\n"
"    db = mix(db, abs(dc)-.001, clamp(iTime-10.,0.,1.));\n"
"    add(sdf, vec2(db,1.), sdf);\n"
"}\n"
"\n"
"void texture_scene(in vec3 x, out vec2 sdf)\n"
"{\n"
"    vec3 y = x;\n"
"    x.xy += vec2(cos(.3*iTime), sin(.3*iTime));\n"
"    \n"
"    sdf.x = x.z;\n"
"    sdf.y = 0.;\n"
"    \n"
"    float res = 8.;\n"
"    vec2 sdb = c.xy;\n"
"    for(float f = 0.; f < 6.; f += 1.)\n"
"    {\n"
"        float v, vp;\n"
"        vec2 vi;\n"
"        dvoronoi(res*x.xy, v, vi, vp);\n"
"        vp /= res;\n"
"        vi /= res;\n"
"        v /= res;\n"
"        add(sdb, vec2(length(x-vec3(vi,0.))-.5*vp, 0.), sdb);\n"
"        res *= 2.;\n"
"        \n"
"        ind += vi/res;\n"
"    }\n"
"    sub(sdf, sdb, sdf);\n"
"    \n"
"    float db = abs(length(y-.1*c.yyx)-.2), \n"
"        dc;\n"
"    dbox3(gR * (y-.1*c.yyx), .2*c.xxx, dc);\n"
"    db = mix(db, abs(dc)-.001, clamp(iTime-5.,0.,1.));\n"
"    doctahedron(gR * (y-.1*c.yyx),.4,.4, dc);\n"
"    db = mix(db, abs(dc)-.001, clamp(iTime-10.,0.,1.));\n"
"    add(sdf, vec2(db,1.), sdf);\n"
"}\n"
"\n"
"void normal(in vec3 x, out vec3 n, in float dx);\n"
"\n"
"void texture_normal(in vec3 x, out vec3 n, in float dx)\n"
"{\n"
"    vec2 s, na;\n"
"    \n"
"    texture_scene(x,s);\n"
"    texture_scene(x+dx*c.xyy, na);\n"
"    n.x = na.x;\n"
"    texture_scene(x+dx*c.yxy, na);\n"
"    n.y = na.x;\n"
"    texture_scene(x+dx*c.yyx, na);\n"
"    n.z = na.x;\n"
"    n = normalize(n-s.x);\n"
"}\n"
"\n"
"void palette(in float scale, out vec3 col)\n"
"{\n"
"    scale = clamp(scale, 1.e-2,.99);\n"
"    const int N = 5;\n"
"    vec3 colors[N] = vec3[N](\n"
"mix(vec3(0.20,0.27,0.35),vec3(1.00,0.00,0.47), clamp(iTime-5.,0.,1.)),\n"
"mix(vec3(0.29,0.37,0.45),vec3(0.80,0.00,0.47), clamp(iTime-5.,0.,1.)),\n"
"mix(vec3(0.36,0.65,0.64),vec3(0.60,0.00,0.47), clamp(iTime-5.,0.,1.)),\n"
"mix(vec3(0.66,0.85,0.80),vec3(0.40,0.00,0.47), clamp(iTime-5.,0.,1.)),\n"
"mix(vec3(0.95,0.92,0.82),c.yyy,clamp(iTime-5.,0.,1.))\n"
"    );\n"
"    colors[0] = mix(colors[0], vec3(0.68,1.00,0.00), clamp(iTime-10.,0.,1.));\n"
"    colors[1] = mix(colors[1], vec3(0.45,0.84,0.00), clamp(iTime-10.,0.,1.));\n"
"    colors[2] = mix(colors[2], vec3(0.01,0.54,0.00), clamp(iTime-10.,0.,1.));\n"
"    colors[3] = mix(colors[3], vec3(0.00,0.82,0.50), clamp(iTime-10.,0.,1.));\n"
"    colors[4] = mix(colors[4], vec3(0.00,1.00,0.51), clamp(iTime-10.,0.,1.));\n"
"	float index = floor(scale*float(N)), \n"
"        remainder = scale*float(N)-index;\n"
"    col = mix(colors[int(index)],colors[int(index)+1], remainder);\n"
"}\n"
"\n"
"float sm(in float d)\n"
"{\n"
"    return smoothstep(1.5/iResolution.y, -1.5/iResolution.y, d);\n"
"}\n"
"\n"
"void main()\n"
"{\n"
"    rot3(vec3(1.1,1.3,1.5)*iTime, gR);\n"
"    vec2 uv = (gl_FragCoord.xy-.5*iResolution.xy)/iResolution.y,\n"
"        s;\n"
"    vec3 col = c.yyy,\n"
"        o = c.yyx+.2*c.yzy,\n"
"        r = c.xyy,\n"
"        t = c.yyy, \n"
"        u = cross(normalize(t-o),-r),\n"
"        dir,\n"
"        n, \n"
"        x,\n"
"        c1 = c.yyy,\n"
"        o0 = o,\n"
"        x0;\n"
"    int N = 150,\n"
"        i;\n"
"        \n"
"    vec3 color1 = vec3(0.52,1.00,0.42);\n"
"        \n"
"    float d;\n"
"    t = uv.x * r + uv.y * u;\n"
"    dir = normalize(t-o);\n"
"    d = 0.;//-(o.z)/dir.y;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        scene(x,s);\n"
"        if(s.x < 1.e-3)break;\n"
"        d += s.x;//min(s.x,2.e-1);\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        if(s.y == 1.)\n"
"        {\n"
"            vec3 l = .5*c.yyz;\n"
"            normal(x,n, 2.e-5);\n"
"            \n"
"            col = c.xxx;\n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + 1.7*col*pow(abs(dot(reflect(l,n),dir)),2.); \n"
"        }\n"
"        else col = c.yyy;\n"
"    }\n"
"    else col = c.yyy;\n"
"    \n"
"    for(i = 0; i<N; ++i)\n"
"    {\n"
"     	x = o + d * dir;\n"
"        texture_scene(x,s);\n"
"        if(s.x < 1.e-3)break;\n"
"        d += s.x;//min(s.x,2.e-1);\n"
"    }\n"
"    \n"
"    if(i < N)\n"
"    {\n"
"        x0 = x;\n"
"        \n"
"        vec3 l = x+c.yxy+.5*c.yyx;\n"
"        texture_normal(x,n, 2.e-5);\n"
"        if(s.y == 0.)\n"
"        {\n"
"            float na;\n"
"            lfnoise(2.*ind-iTime, na);\n"
"            palette(.5+.5*na, col);\n"
"            \n"
"//             col = length(col)/sqrt(3.)*c.xxx;\n"
"            \n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + .7*col*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"        }\n"
"        else if(s.y == 1.)\n"
"        {\n"
"            vec3 c1;\n"
"            \n"
"            col = c.xxx;\n"
"            col = .3*col \n"
"                + .5*col*dot(-l, n)\n"
"                + .7*col*pow(abs(dot(reflect(l,n),dir)),2.); \n"
"            \n"
"            for(float k = 0.; k < 3.; k += 1.)\n"
"            {\n"
"                o = x;\n"
"                dir = refract(dir, n, .5);\n"
"                d = 1.e-2;\n"
"                \n"
"                for(i = 0; i<N; ++i)\n"
"                {\n"
"                    x = o + d * dir;\n"
"                    scene(x,s);\n"
"                    if(s.x < 1.e-5)break;\n"
"                    d += s.x;//min(s.x,2.e-3);\n"
"                }\n"
"                \n"
"                if(i < N)\n"
"                {\n"
"                    if(s.y == 1.)\n"
"                    {\n"
"                        vec3 l = .5*c.yyz;\n"
"                        normal(x,n, 2.e-5);\n"
"                        \n"
"                        c1 = c.xxx;\n"
"                        c1 = .3*c1 \n"
"                            + .5*c1*dot(-l, n)\n"
"                            + 1.7*c1*pow(abs(dot(reflect(l,n),dir)),2.); \n"
"                    }\n"
"                    else c1 = c.yyy;\n"
"                }\n"
"                else c1 = c.yyy;\n"
"                col = mix(col, c1, .54);\n"
"                \n"
"                for(i = 0; i<N; ++i)\n"
"                {\n"
"                    x = o + d * dir;\n"
"                    texture_scene(x,s);\n"
"                    if(s.x < 1.e-3)break;\n"
"                    d += s.x;//min(s.x,2.e-1);\n"
"                }\n"
"                \n"
"                if(i<N)\n"
"                {\n"
"                    vec3 l = x+c.yxy+.5*c.yyx;\n"
"                    texture_normal(x,n, 2.e-5);\n"
"                    if(s.y == 0.)\n"
"                    {\n"
"                        float na;\n"
"                        lfnoise(ind, na);\n"
"                        palette(.5+.5*na, c1);\n"
"                        \n"
"                        c1 = .4*c1 \n"
"                            + .5*c1*dot(-l, n)\n"
"                            + .7*c1*pow(abs(dot(reflect(l,n),dir)),2.);\n"
"                    }\n"
"//                     else c1 = c.yyy;\n"
"                    \n"
"                    col = mix(col, c1, .3);\n"
"                }\n"
"//                 else col = c.yyy;\n"
"            }\n"
"        }\n"
"//         else col *= -1.;\n"
"    }\n"
"//     else col = c.yyx;\n"
"        \n"
"    float da = 1.;\n"
"//     (abs(length(x0.xy)-.2)-.03),\n"
"//         db;\n"
"    scene(vec3(uv,.2), s);\n"
"    da = abs(s.x-.1)-.003;\n"
"//     dbox(x.xy, .4*c.xx, db);\n"
"//     db = abs(db)-.03;\n"
"//     da = mix(da, db, clamp(iTime-5.,0.,1.));\n"
"    col = mix(col, 8.*col, sm(da/20.));\n"
"    col = 1.5*col*col;\n"
"    \n"
"    gl_FragColor = vec4(clamp(col,0.,1.),1.);\n"
"}\n"
"\0";
void Loadrand()
{
    int rand_size = strlen(rand_source);
    rand_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rand_handle, 1, (GLchar **)&rand_source, &rand_size);
    glCompileShader(rand_handle);
#ifdef DEBUG
    printf("---> rand Shader:\n");
    debug(rand_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash11()
{
    int hash11_size = strlen(hash11_source);
    hash11_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash11_handle, 1, (GLchar **)&hash11_source, &hash11_size);
    glCompileShader(hash11_handle);
#ifdef DEBUG
    printf("---> hash11 Shader:\n");
    debug(hash11_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash12()
{
    int hash12_size = strlen(hash12_source);
    hash12_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash12_handle, 1, (GLchar **)&hash12_source, &hash12_size);
    glCompileShader(hash12_handle);
#ifdef DEBUG
    printf("---> hash12 Shader:\n");
    debug(hash12_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash21()
{
    int hash21_size = strlen(hash21_source);
    hash21_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash21_handle, 1, (GLchar **)&hash21_source, &hash21_size);
    glCompileShader(hash21_handle);
#ifdef DEBUG
    printf("---> hash21 Shader:\n");
    debug(hash21_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash22()
{
    int hash22_size = strlen(hash22_source);
    hash22_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash22_handle, 1, (GLchar **)&hash22_source, &hash22_size);
    glCompileShader(hash22_handle);
#ifdef DEBUG
    printf("---> hash22 Shader:\n");
    debug(hash22_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash31()
{
    int hash31_size = strlen(hash31_source);
    hash31_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash31_handle, 1, (GLchar **)&hash31_source, &hash31_size);
    glCompileShader(hash31_handle);
#ifdef DEBUG
    printf("---> hash31 Shader:\n");
    debug(hash31_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadstroke()
{
    int stroke_size = strlen(stroke_source);
    stroke_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(stroke_handle, 1, (GLchar **)&stroke_source, &stroke_size);
    glCompileShader(stroke_handle);
#ifdef DEBUG
    printf("---> stroke Shader:\n");
    debug(stroke_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadlfnoise()
{
    int lfnoise_size = strlen(lfnoise_source);
    lfnoise_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(lfnoise_handle, 1, (GLchar **)&lfnoise_source, &lfnoise_size);
    glCompileShader(lfnoise_handle);
#ifdef DEBUG
    printf("---> lfnoise Shader:\n");
    debug(lfnoise_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddvoronoi()
{
    int dvoronoi_size = strlen(dvoronoi_source);
    dvoronoi_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dvoronoi_handle, 1, (GLchar **)&dvoronoi_source, &dvoronoi_size);
    glCompileShader(dvoronoi_handle);
#ifdef DEBUG
    printf("---> dvoronoi Shader:\n");
    debug(dvoronoi_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddbox()
{
    int dbox_size = strlen(dbox_source);
    dbox_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dbox_handle, 1, (GLchar **)&dbox_source, &dbox_size);
    glCompileShader(dbox_handle);
#ifdef DEBUG
    printf("---> dbox Shader:\n");
    debug(dbox_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddlinesegment()
{
    int dlinesegment_size = strlen(dlinesegment_source);
    dlinesegment_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dlinesegment_handle, 1, (GLchar **)&dlinesegment_source, &dlinesegment_size);
    glCompileShader(dlinesegment_handle);
#ifdef DEBUG
    printf("---> dlinesegment Shader:\n");
    debug(dlinesegment_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadsmoothmin()
{
    int smoothmin_size = strlen(smoothmin_source);
    smoothmin_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(smoothmin_handle, 1, (GLchar **)&smoothmin_source, &smoothmin_size);
    glCompileShader(smoothmin_handle);
#ifdef DEBUG
    printf("---> smoothmin Shader:\n");
    debug(smoothmin_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadadd()
{
    int add_size = strlen(add_source);
    add_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(add_handle, 1, (GLchar **)&add_source, &add_size);
    glCompileShader(add_handle);
#ifdef DEBUG
    printf("---> add Shader:\n");
    debug(add_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadnormal()
{
    int normal_size = strlen(normal_source);
    normal_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(normal_handle, 1, (GLchar **)&normal_source, &normal_size);
    glCompileShader(normal_handle);
#ifdef DEBUG
    printf("---> normal Shader:\n");
    debug(normal_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddbox3()
{
    int dbox3_size = strlen(dbox3_source);
    dbox3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dbox3_handle, 1, (GLchar **)&dbox3_source, &dbox3_size);
    glCompileShader(dbox3_handle);
#ifdef DEBUG
    printf("---> dbox3 Shader:\n");
    debug(dbox3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadrot3()
{
    int rot3_size = strlen(rot3_source);
    rot3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rot3_handle, 1, (GLchar **)&rot3_source, &rot3_size);
    glCompileShader(rot3_handle);
#ifdef DEBUG
    printf("---> rot3 Shader:\n");
    debug(rot3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddbox210()
{
    int dbox210_size = strlen(dbox210_source);
    dbox210_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dbox210_handle, 1, (GLchar **)&dbox210_source, &dbox210_size);
    glCompileShader(dbox210_handle);
#ifdef DEBUG
    printf("---> dbox210 Shader:\n");
    debug(dbox210_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddspline2()
{
    int dspline2_size = strlen(dspline2_source);
    dspline2_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dspline2_handle, 1, (GLchar **)&dspline2_source, &dspline2_size);
    glCompileShader(dspline2_handle);
#ifdef DEBUG
    printf("---> dspline2 Shader:\n");
    debug(dspline2_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadzextrude()
{
    int zextrude_size = strlen(zextrude_source);
    zextrude_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(zextrude_handle, 1, (GLchar **)&zextrude_source, &zextrude_size);
    glCompileShader(zextrude_handle);
#ifdef DEBUG
    printf("---> zextrude Shader:\n");
    debug(zextrude_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadmfnoise()
{
    int mfnoise_size = strlen(mfnoise_source);
    mfnoise_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(mfnoise_handle, 1, (GLchar **)&mfnoise_source, &mfnoise_size);
    glCompileShader(mfnoise_handle);
#ifdef DEBUG
    printf("---> mfnoise Shader:\n");
    debug(mfnoise_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadrshort()
{
    int rshort_size = strlen(rshort_source);
    rshort_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rshort_handle, 1, (GLchar **)&rshort_source, &rshort_size);
    glCompileShader(rshort_handle);
#ifdef DEBUG
    printf("---> rshort Shader:\n");
    debug(rshort_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadrfloat()
{
    int rfloat_size = strlen(rfloat_source);
    rfloat_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rfloat_handle, 1, (GLchar **)&rfloat_source, &rfloat_size);
    glCompileShader(rfloat_handle);
#ifdef DEBUG
    printf("---> rfloat Shader:\n");
    debug(rfloat_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddcircle()
{
    int dcircle_size = strlen(dcircle_source);
    dcircle_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dcircle_handle, 1, (GLchar **)&dcircle_source, &dcircle_size);
    glCompileShader(dcircle_handle);
#ifdef DEBUG
    printf("---> dcircle Shader:\n");
    debug(dcircle_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddrhomboid()
{
    int drhomboid_size = strlen(drhomboid_source);
    drhomboid_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(drhomboid_handle, 1, (GLchar **)&drhomboid_source, &drhomboid_size);
    glCompileShader(drhomboid_handle);
#ifdef DEBUG
    printf("---> drhomboid Shader:\n");
    debug(drhomboid_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddcirclesegment()
{
    int dcirclesegment_size = strlen(dcirclesegment_source);
    dcirclesegment_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dcirclesegment_handle, 1, (GLchar **)&dcirclesegment_source, &dcirclesegment_size);
    glCompileShader(dcirclesegment_handle);
#ifdef DEBUG
    printf("---> dcirclesegment Shader:\n");
    debug(dcirclesegment_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddglyph()
{
    int dglyph_size = strlen(dglyph_source);
    dglyph_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dglyph_handle, 1, (GLchar **)&dglyph_source, &dglyph_size);
    glCompileShader(dglyph_handle);
#ifdef DEBUG
    printf("---> dglyph Shader:\n");
    debug(dglyph_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddstring()
{
    int dstring_size = strlen(dstring_source);
    dstring_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dstring_handle, 1, (GLchar **)&dstring_source, &dstring_size);
    glCompileShader(dstring_handle);
#ifdef DEBUG
    printf("---> dstring Shader:\n");
    debug(dstring_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddfloat()
{
    int dfloat_size = strlen(dfloat_source);
    dfloat_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dfloat_handle, 1, (GLchar **)&dfloat_source, &dfloat_size);
    glCompileShader(dfloat_handle);
#ifdef DEBUG
    printf("---> dfloat Shader:\n");
    debug(dfloat_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddint()
{
    int dint_size = strlen(dint_source);
    dint_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dint_handle, 1, (GLchar **)&dint_source, &dint_size);
    glCompileShader(dint_handle);
#ifdef DEBUG
    printf("---> dint Shader:\n");
    debug(dint_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddtime()
{
    int dtime_size = strlen(dtime_source);
    dtime_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dtime_handle, 1, (GLchar **)&dtime_source, &dtime_size);
    glCompileShader(dtime_handle);
#ifdef DEBUG
    printf("---> dtime Shader:\n");
    debug(dtime_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadaddwindow()
{
    int addwindow_size = strlen(addwindow_source);
    addwindow_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(addwindow_handle, 1, (GLchar **)&addwindow_source, &addwindow_size);
    glCompileShader(addwindow_handle);
#ifdef DEBUG
    printf("---> addwindow Shader:\n");
    debug(addwindow_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadddeadline()
{
    int ddeadline_size = strlen(ddeadline_source);
    ddeadline_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(ddeadline_handle, 1, (GLchar **)&ddeadline_source, &ddeadline_size);
    glCompileShader(ddeadline_handle);
#ifdef DEBUG
    printf("---> ddeadline Shader:\n");
    debug(ddeadline_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddpolygon()
{
    int dpolygon_size = strlen(dpolygon_source);
    dpolygon_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dpolygon_handle, 1, (GLchar **)&dpolygon_source, &dpolygon_size);
    glCompileShader(dpolygon_handle);
#ifdef DEBUG
    printf("---> dpolygon Shader:\n");
    debug(dpolygon_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddspacepigs()
{
    int dspacepigs_size = strlen(dspacepigs_source);
    dspacepigs_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dspacepigs_handle, 1, (GLchar **)&dspacepigs_source, &dspacepigs_size);
    glCompileShader(dspacepigs_handle);
#ifdef DEBUG
    printf("---> dspacepigs Shader:\n");
    debug(dspacepigs_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadanalytical_box()
{
    int analytical_box_size = strlen(analytical_box_source);
    analytical_box_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(analytical_box_handle, 1, (GLchar **)&analytical_box_source, &analytical_box_size);
    glCompileShader(analytical_box_handle);
#ifdef DEBUG
    printf("---> analytical_box Shader:\n");
    debug(analytical_box_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadhash33()
{
    int hash33_size = strlen(hash33_source);
    hash33_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hash33_handle, 1, (GLchar **)&hash33_source, &hash33_size);
    glCompileShader(hash33_handle);
#ifdef DEBUG
    printf("---> hash33 Shader:\n");
    debug(hash33_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddvoronoi3()
{
    int dvoronoi3_size = strlen(dvoronoi3_source);
    dvoronoi3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dvoronoi3_handle, 1, (GLchar **)&dvoronoi3_source, &dvoronoi3_size);
    glCompileShader(dvoronoi3_handle);
#ifdef DEBUG
    printf("---> dvoronoi3 Shader:\n");
    debug(dvoronoi3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddsmoothvoronoi3()
{
    int dsmoothvoronoi3_size = strlen(dsmoothvoronoi3_source);
    dsmoothvoronoi3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dsmoothvoronoi3_handle, 1, (GLchar **)&dsmoothvoronoi3_source, &dsmoothvoronoi3_size);
    glCompileShader(dsmoothvoronoi3_handle);
#ifdef DEBUG
    printf("---> dsmoothvoronoi3 Shader:\n");
    debug(dsmoothvoronoi3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddstar()
{
    int dstar_size = strlen(dstar_source);
    dstar_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dstar_handle, 1, (GLchar **)&dstar_source, &dstar_size);
    glCompileShader(dstar_handle);
#ifdef DEBUG
    printf("---> dstar Shader:\n");
    debug(dstar_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadsmoothmax()
{
    int smoothmax_size = strlen(smoothmax_source);
    smoothmax_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(smoothmax_handle, 1, (GLchar **)&smoothmax_source, &smoothmax_size);
    glCompileShader(smoothmax_handle);
#ifdef DEBUG
    printf("---> smoothmax Shader:\n");
    debug(smoothmax_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddstar3()
{
    int dstar3_size = strlen(dstar3_source);
    dstar3_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dstar3_handle, 1, (GLchar **)&dstar3_source, &dstar3_size);
    glCompileShader(dstar3_handle);
#ifdef DEBUG
    printf("---> dstar3 Shader:\n");
    debug(dstar3_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddhexagonpattern()
{
    int dhexagonpattern_size = strlen(dhexagonpattern_source);
    dhexagonpattern_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dhexagonpattern_handle, 1, (GLchar **)&dhexagonpattern_source, &dhexagonpattern_size);
    glCompileShader(dhexagonpattern_handle);
#ifdef DEBUG
    printf("---> dhexagonpattern Shader:\n");
    debug(dhexagonpattern_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddmercury()
{
    int dmercury_size = strlen(dmercury_source);
    dmercury_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dmercury_handle, 1, (GLchar **)&dmercury_source, &dmercury_size);
    glCompileShader(dmercury_handle);
#ifdef DEBUG
    printf("---> dmercury Shader:\n");
    debug(dmercury_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddtriangle()
{
    int dtriangle_size = strlen(dtriangle_source);
    dtriangle_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dtriangle_handle, 1, (GLchar **)&dtriangle_source, &dtriangle_size);
    glCompileShader(dtriangle_handle);
#ifdef DEBUG
    printf("---> dtriangle Shader:\n");
    debug(dtriangle_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadrot()
{
    int rot_size = strlen(rot_source);
    rot_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(rot_handle, 1, (GLchar **)&rot_source, &rot_size);
    glCompileShader(rot_handle);
#ifdef DEBUG
    printf("---> rot Shader:\n");
    debug(rot_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddschnappsgirls()
{
    int dschnappsgirls_size = strlen(dschnappsgirls_source);
    dschnappsgirls_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dschnappsgirls_handle, 1, (GLchar **)&dschnappsgirls_source, &dschnappsgirls_size);
    glCompileShader(dschnappsgirls_handle);
#ifdef DEBUG
    printf("---> dschnappsgirls Shader:\n");
    debug(dschnappsgirls_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddhaujobb()
{
    int dhaujobb_size = strlen(dhaujobb_source);
    dhaujobb_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dhaujobb_handle, 1, (GLchar **)&dhaujobb_source, &dhaujobb_size);
    glCompileShader(dhaujobb_handle);
#ifdef DEBUG
    printf("---> dhaujobb Shader:\n");
    debug(dhaujobb_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddkewlers()
{
    int dkewlers_size = strlen(dkewlers_source);
    dkewlers_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dkewlers_handle, 1, (GLchar **)&dkewlers_source, &dkewlers_size);
    glCompileShader(dkewlers_handle);
#ifdef DEBUG
    printf("---> dkewlers Shader:\n");
    debug(dkewlers_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddfarbrausch()
{
    int dfarbrausch_size = strlen(dfarbrausch_source);
    dfarbrausch_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(dfarbrausch_handle, 1, (GLchar **)&dfarbrausch_source, &dfarbrausch_size);
    glCompileShader(dfarbrausch_handle);
#ifdef DEBUG
    printf("---> dfarbrausch Shader:\n");
    debug(dfarbrausch_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadd5711()
{
    int d5711_size = strlen(d5711_source);
    d5711_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(d5711_handle, 1, (GLchar **)&d5711_source, &d5711_size);
    glCompileShader(d5711_handle);
#ifdef DEBUG
    printf("---> d5711 Shader:\n");
    debug(d5711_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loadsub()
{
    int sub_size = strlen(sub_source);
    sub_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sub_handle, 1, (GLchar **)&sub_source, &sub_size);
    glCompileShader(sub_handle);
#ifdef DEBUG
    printf("---> sub Shader:\n");
    debug(sub_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}
void Loaddoctahedron()
{
    int doctahedron_size = strlen(doctahedron_source);
    doctahedron_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(doctahedron_handle, 1, (GLchar **)&doctahedron_source, &doctahedron_size);
    glCompileShader(doctahedron_handle);
#ifdef DEBUG
    printf("---> doctahedron Shader:\n");
    debug(doctahedron_handle);
    printf(">>>>\n");
#endif
    progress += .2/(float)nsymbols;
}

void LoadSymbols()
{
    Loadrand();
    updateBar();
    Loadhash11();
    updateBar();
    Loadhash12();
    updateBar();
    Loadhash21();
    updateBar();
    Loadhash22();
    updateBar();
    Loadhash31();
    updateBar();
    Loadstroke();
    updateBar();
    Loadlfnoise();
    updateBar();
    Loaddvoronoi();
    updateBar();
    Loaddbox();
    updateBar();
    Loaddlinesegment();
    updateBar();
    Loadsmoothmin();
    updateBar();
    Loadadd();
    updateBar();
    Loadnormal();
    updateBar();
    Loaddbox3();
    updateBar();
    Loadrot3();
    updateBar();
    Loaddbox210();
    updateBar();
    Loaddspline2();
    updateBar();
    Loadzextrude();
    updateBar();
    Loadmfnoise();
    updateBar();
    Loadrshort();
    updateBar();
    Loadrfloat();
    updateBar();
    Loaddcircle();
    updateBar();
    Loaddrhomboid();
    updateBar();
    Loaddcirclesegment();
    updateBar();
    Loaddglyph();
    updateBar();
    Loaddstring();
    updateBar();
    Loaddfloat();
    updateBar();
    Loaddint();
    updateBar();
    Loaddtime();
    updateBar();
    Loadaddwindow();
    updateBar();
    Loadddeadline();
    updateBar();
    Loaddpolygon();
    updateBar();
    Loaddspacepigs();
    updateBar();
    Loadanalytical_box();
    updateBar();
    Loadhash33();
    updateBar();
    Loaddvoronoi3();
    updateBar();
    Loaddsmoothvoronoi3();
    updateBar();
    Loaddstar();
    updateBar();
    Loadsmoothmax();
    updateBar();
    Loaddstar3();
    updateBar();
    Loaddhexagonpattern();
    updateBar();
    Loaddmercury();
    updateBar();
    Loaddtriangle();
    updateBar();
    Loadrot();
    updateBar();
    Loaddschnappsgirls();
    updateBar();
    Loaddhaujobb();
    updateBar();
    Loaddkewlers();
    updateBar();
    Loaddfarbrausch();
    updateBar();
    Loadd5711();
    updateBar();
    Loadsub();
    updateBar();
    Loaddoctahedron();
    updateBar();
}
int ocean_program, ocean_handle, logo210_program, logo210_handle, graffiti_program, graffiti_handle, starsky_program, starsky_handle, text_program, text_handle, post_program, post_handle, deadline_program, deadline_handle, hydrant_program, hydrant_handle, watercubes_program, watercubes_handle, glitchcity_program, glitchcity_handle, greetings_program, greetings_handle, fractal_program, fractal_handle;
int ocean_iTime_location,ocean_iResolution_location,ocean_iFader0_location,ocean_iFader1_location,ocean_iFader2_location,ocean_iFader3_location,ocean_iFader4_location,ocean_iFader5_location,ocean_iFader6_location,ocean_iFader7_location;
int logo210_iTime_location,logo210_iResolution_location,logo210_iFader0_location,logo210_iFader1_location,logo210_iFader2_location,logo210_iFader3_location,logo210_iFader4_location,logo210_iFader5_location,logo210_iFader6_location,logo210_iFader7_location;
int graffiti_iTime_location,graffiti_iResolution_location,graffiti_iFader0_location,graffiti_iFader1_location,graffiti_iFader2_location,graffiti_iFader3_location,graffiti_iFader4_location,graffiti_iFader5_location,graffiti_iFader6_location,graffiti_iFader7_location;
int starsky_iTime_location,starsky_iResolution_location,starsky_iFader0_location,starsky_iFader1_location,starsky_iFader2_location,starsky_iFader3_location,starsky_iFader4_location,starsky_iFader5_location,starsky_iFader6_location,starsky_iFader7_location;
int text_iFontWidth_location,text_iTime_location,text_iResolution_location,text_iChannel0_location,text_iFont_location,text_iFSAA_location,text_iFader0_location,text_iFader1_location,text_iFader2_location,text_iFader3_location,text_iFader4_location,text_iFader5_location,text_iFader6_location,text_iFader7_location;
int post_iFSAA_location,post_iResolution_location,post_iChannel0_location,post_iTime_location;
int deadline_iTime_location,deadline_iResolution_location,deadline_iFader0_location,deadline_iFader1_location,deadline_iFader2_location,deadline_iFader3_location,deadline_iFader4_location,deadline_iFader5_location,deadline_iFader6_location,deadline_iFader7_location;
int hydrant_iTime_location,hydrant_iResolution_location,hydrant_iFader0_location,hydrant_iFader1_location,hydrant_iFader2_location,hydrant_iFader3_location,hydrant_iFader4_location,hydrant_iFader5_location,hydrant_iFader6_location,hydrant_iFader7_location;
int watercubes_iTime_location,watercubes_iResolution_location,watercubes_iFader0_location,watercubes_iFader1_location,watercubes_iFader2_location,watercubes_iFader3_location,watercubes_iFader4_location,watercubes_iFader5_location,watercubes_iFader6_location,watercubes_iFader7_location;
int glitchcity_iTime_location,glitchcity_iResolution_location,glitchcity_iFader0_location,glitchcity_iFader1_location,glitchcity_iFader2_location,glitchcity_iFader3_location,glitchcity_iFader4_location,glitchcity_iFader5_location,glitchcity_iFader6_location,glitchcity_iFader7_location;
int greetings_iTime_location,greetings_iResolution_location,greetings_iFader0_location,greetings_iFader1_location,greetings_iFader2_location,greetings_iFader3_location,greetings_iFader4_location,greetings_iFader5_location,greetings_iFader6_location,greetings_iFader7_location;
int fractal_iTime_location,fractal_iResolution_location,fractal_iFader0_location,fractal_iFader1_location,fractal_iFader2_location,fractal_iFader3_location,fractal_iFader4_location,fractal_iFader5_location,fractal_iFader6_location,fractal_iFader7_location;
const int nprograms = 12;

void Loadocean()
{
    int ocean_size = strlen(ocean_source);
    ocean_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(ocean_handle, 1, (GLchar **)&ocean_source, &ocean_size);
    glCompileShader(ocean_handle);
#ifdef DEBUG
    printf("---> ocean Shader:\n");
    debug(ocean_handle);
    printf(">>>>\n");
#endif
    ocean_program = glCreateProgram();
    glAttachShader(ocean_program,ocean_handle);
    glAttachShader(ocean_program,rand_handle);
    glAttachShader(ocean_program,hash11_handle);
    glAttachShader(ocean_program,hash12_handle);
    glAttachShader(ocean_program,hash21_handle);
    glAttachShader(ocean_program,hash22_handle);
    glAttachShader(ocean_program,hash31_handle);
    glAttachShader(ocean_program,stroke_handle);
    glAttachShader(ocean_program,lfnoise_handle);
    glAttachShader(ocean_program,dvoronoi_handle);
    glAttachShader(ocean_program,dbox_handle);
    glAttachShader(ocean_program,dlinesegment_handle);
    glAttachShader(ocean_program,smoothmin_handle);
    glAttachShader(ocean_program,add_handle);
    glAttachShader(ocean_program,normal_handle);
    glLinkProgram(ocean_program);
#ifdef DEBUG
    printf("---> ocean Program:\n");
    debugp(ocean_program);
    printf(">>>>\n");
#endif
    glUseProgram(ocean_program);
    ocean_iTime_location = glGetUniformLocation(ocean_program, "iTime");
    ocean_iResolution_location = glGetUniformLocation(ocean_program, "iResolution");
    ocean_iFader0_location = glGetUniformLocation(ocean_program, "iFader0");
    ocean_iFader1_location = glGetUniformLocation(ocean_program, "iFader1");
    ocean_iFader2_location = glGetUniformLocation(ocean_program, "iFader2");
    ocean_iFader3_location = glGetUniformLocation(ocean_program, "iFader3");
    ocean_iFader4_location = glGetUniformLocation(ocean_program, "iFader4");
    ocean_iFader5_location = glGetUniformLocation(ocean_program, "iFader5");
    ocean_iFader6_location = glGetUniformLocation(ocean_program, "iFader6");
    ocean_iFader7_location = glGetUniformLocation(ocean_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadlogo210()
{
    int logo210_size = strlen(logo210_source);
    logo210_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(logo210_handle, 1, (GLchar **)&logo210_source, &logo210_size);
    glCompileShader(logo210_handle);
#ifdef DEBUG
    printf("---> logo210 Shader:\n");
    debug(logo210_handle);
    printf(">>>>\n");
#endif
    logo210_program = glCreateProgram();
    glAttachShader(logo210_program,logo210_handle);
    glAttachShader(logo210_program,dbox3_handle);
    glAttachShader(logo210_program,rot3_handle);
    glAttachShader(logo210_program,stroke_handle);
    glAttachShader(logo210_program,add_handle);
    glAttachShader(logo210_program,dbox210_handle);
    glAttachShader(logo210_program,normal_handle);
    glLinkProgram(logo210_program);
#ifdef DEBUG
    printf("---> logo210 Program:\n");
    debugp(logo210_program);
    printf(">>>>\n");
#endif
    glUseProgram(logo210_program);
    logo210_iTime_location = glGetUniformLocation(logo210_program, "iTime");
    logo210_iResolution_location = glGetUniformLocation(logo210_program, "iResolution");
    logo210_iFader0_location = glGetUniformLocation(logo210_program, "iFader0");
    logo210_iFader1_location = glGetUniformLocation(logo210_program, "iFader1");
    logo210_iFader2_location = glGetUniformLocation(logo210_program, "iFader2");
    logo210_iFader3_location = glGetUniformLocation(logo210_program, "iFader3");
    logo210_iFader4_location = glGetUniformLocation(logo210_program, "iFader4");
    logo210_iFader5_location = glGetUniformLocation(logo210_program, "iFader5");
    logo210_iFader6_location = glGetUniformLocation(logo210_program, "iFader6");
    logo210_iFader7_location = glGetUniformLocation(logo210_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadgraffiti()
{
    int graffiti_size = strlen(graffiti_source);
    graffiti_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(graffiti_handle, 1, (GLchar **)&graffiti_source, &graffiti_size);
    glCompileShader(graffiti_handle);
#ifdef DEBUG
    printf("---> graffiti Shader:\n");
    debug(graffiti_handle);
    printf(">>>>\n");
#endif
    graffiti_program = glCreateProgram();
    glAttachShader(graffiti_program,graffiti_handle);
    glAttachShader(graffiti_program,hash22_handle);
    glAttachShader(graffiti_program,rand_handle);
    glAttachShader(graffiti_program,lfnoise_handle);
    glAttachShader(graffiti_program,dspline2_handle);
    glAttachShader(graffiti_program,dlinesegment_handle);
    glAttachShader(graffiti_program,stroke_handle);
    glAttachShader(graffiti_program,smoothmin_handle);
    glAttachShader(graffiti_program,dvoronoi_handle);
    glAttachShader(graffiti_program,zextrude_handle);
    glAttachShader(graffiti_program,normal_handle);
    glLinkProgram(graffiti_program);
#ifdef DEBUG
    printf("---> graffiti Program:\n");
    debugp(graffiti_program);
    printf(">>>>\n");
#endif
    glUseProgram(graffiti_program);
    graffiti_iTime_location = glGetUniformLocation(graffiti_program, "iTime");
    graffiti_iResolution_location = glGetUniformLocation(graffiti_program, "iResolution");
    graffiti_iFader0_location = glGetUniformLocation(graffiti_program, "iFader0");
    graffiti_iFader1_location = glGetUniformLocation(graffiti_program, "iFader1");
    graffiti_iFader2_location = glGetUniformLocation(graffiti_program, "iFader2");
    graffiti_iFader3_location = glGetUniformLocation(graffiti_program, "iFader3");
    graffiti_iFader4_location = glGetUniformLocation(graffiti_program, "iFader4");
    graffiti_iFader5_location = glGetUniformLocation(graffiti_program, "iFader5");
    graffiti_iFader6_location = glGetUniformLocation(graffiti_program, "iFader6");
    graffiti_iFader7_location = glGetUniformLocation(graffiti_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadstarsky()
{
    int starsky_size = strlen(starsky_source);
    starsky_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(starsky_handle, 1, (GLchar **)&starsky_source, &starsky_size);
    glCompileShader(starsky_handle);
#ifdef DEBUG
    printf("---> starsky Shader:\n");
    debug(starsky_handle);
    printf(">>>>\n");
#endif
    starsky_program = glCreateProgram();
    glAttachShader(starsky_program,starsky_handle);
    glAttachShader(starsky_program,hash22_handle);
    glAttachShader(starsky_program,rand_handle);
    glAttachShader(starsky_program,lfnoise_handle);
    glAttachShader(starsky_program,mfnoise_handle);
    glAttachShader(starsky_program,dvoronoi_handle);
    glAttachShader(starsky_program,stroke_handle);
    glAttachShader(starsky_program,dbox_handle);
    glAttachShader(starsky_program,dbox3_handle);
    glAttachShader(starsky_program,add_handle);
    glAttachShader(starsky_program,normal_handle);
    glLinkProgram(starsky_program);
#ifdef DEBUG
    printf("---> starsky Program:\n");
    debugp(starsky_program);
    printf(">>>>\n");
#endif
    glUseProgram(starsky_program);
    starsky_iTime_location = glGetUniformLocation(starsky_program, "iTime");
    starsky_iResolution_location = glGetUniformLocation(starsky_program, "iResolution");
    starsky_iFader0_location = glGetUniformLocation(starsky_program, "iFader0");
    starsky_iFader1_location = glGetUniformLocation(starsky_program, "iFader1");
    starsky_iFader2_location = glGetUniformLocation(starsky_program, "iFader2");
    starsky_iFader3_location = glGetUniformLocation(starsky_program, "iFader3");
    starsky_iFader4_location = glGetUniformLocation(starsky_program, "iFader4");
    starsky_iFader5_location = glGetUniformLocation(starsky_program, "iFader5");
    starsky_iFader6_location = glGetUniformLocation(starsky_program, "iFader6");
    starsky_iFader7_location = glGetUniformLocation(starsky_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadtext()
{
    int text_size = strlen(text_source);
    text_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(text_handle, 1, (GLchar **)&text_source, &text_size);
    glCompileShader(text_handle);
#ifdef DEBUG
    printf("---> text Shader:\n");
    debug(text_handle);
    printf(">>>>\n");
#endif
    text_program = glCreateProgram();
    glAttachShader(text_program,text_handle);
    glAttachShader(text_program,rand_handle);
    glAttachShader(text_program,lfnoise_handle);
    glAttachShader(text_program,rshort_handle);
    glAttachShader(text_program,rfloat_handle);
    glAttachShader(text_program,dbox_handle);
    glAttachShader(text_program,dcircle_handle);
    glAttachShader(text_program,dlinesegment_handle);
    glAttachShader(text_program,drhomboid_handle);
    glAttachShader(text_program,dcirclesegment_handle);
    glAttachShader(text_program,stroke_handle);
    glAttachShader(text_program,dglyph_handle);
    glAttachShader(text_program,dstring_handle);
    glAttachShader(text_program,dfloat_handle);
    glAttachShader(text_program,smoothmin_handle);
    glAttachShader(text_program,dint_handle);
    glAttachShader(text_program,dtime_handle);
    glAttachShader(text_program,addwindow_handle);
    glAttachShader(text_program,dvoronoi_handle);
    glLinkProgram(text_program);
#ifdef DEBUG
    printf("---> text Program:\n");
    debugp(text_program);
    printf(">>>>\n");
#endif
    glUseProgram(text_program);
    text_iFontWidth_location = glGetUniformLocation(text_program, "iFontWidth");
    text_iTime_location = glGetUniformLocation(text_program, "iTime");
    text_iResolution_location = glGetUniformLocation(text_program, "iResolution");
    text_iChannel0_location = glGetUniformLocation(text_program, "iChannel0");
    text_iFont_location = glGetUniformLocation(text_program, "iFont");
    text_iFSAA_location = glGetUniformLocation(text_program, "iFSAA");
    text_iFader0_location = glGetUniformLocation(text_program, "iFader0");
    text_iFader1_location = glGetUniformLocation(text_program, "iFader1");
    text_iFader2_location = glGetUniformLocation(text_program, "iFader2");
    text_iFader3_location = glGetUniformLocation(text_program, "iFader3");
    text_iFader4_location = glGetUniformLocation(text_program, "iFader4");
    text_iFader5_location = glGetUniformLocation(text_program, "iFader5");
    text_iFader6_location = glGetUniformLocation(text_program, "iFader6");
    text_iFader7_location = glGetUniformLocation(text_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadpost()
{
    int post_size = strlen(post_source);
    post_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(post_handle, 1, (GLchar **)&post_source, &post_size);
    glCompileShader(post_handle);
#ifdef DEBUG
    printf("---> post Shader:\n");
    debug(post_handle);
    printf(">>>>\n");
#endif
    post_program = glCreateProgram();
    glAttachShader(post_program,post_handle);
    glAttachShader(post_program,rand_handle);
    glAttachShader(post_program,lfnoise_handle);
    glAttachShader(post_program,stroke_handle);
    glAttachShader(post_program,dvoronoi_handle);
    glAttachShader(post_program,hash22_handle);
    glAttachShader(post_program,rot3_handle);
    glAttachShader(post_program,dbox3_handle);
    glAttachShader(post_program,add_handle);
    glAttachShader(post_program,normal_handle);
    glLinkProgram(post_program);
#ifdef DEBUG
    printf("---> post Program:\n");
    debugp(post_program);
    printf(">>>>\n");
#endif
    glUseProgram(post_program);
    post_iFSAA_location = glGetUniformLocation(post_program, "iFSAA");
    post_iResolution_location = glGetUniformLocation(post_program, "iResolution");
    post_iChannel0_location = glGetUniformLocation(post_program, "iChannel0");
    post_iTime_location = glGetUniformLocation(post_program, "iTime");
    progress += .2/(float)nprograms;
}

void Loaddeadline()
{
    int deadline_size = strlen(deadline_source);
    deadline_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(deadline_handle, 1, (GLchar **)&deadline_source, &deadline_size);
    glCompileShader(deadline_handle);
#ifdef DEBUG
    printf("---> deadline Shader:\n");
    debug(deadline_handle);
    printf(">>>>\n");
#endif
    deadline_program = glCreateProgram();
    glAttachShader(deadline_program,deadline_handle);
    glAttachShader(deadline_program,rand_handle);
    glAttachShader(deadline_program,lfnoise_handle);
    glAttachShader(deadline_program,hash11_handle);
    glAttachShader(deadline_program,hash12_handle);
    glAttachShader(deadline_program,hash22_handle);
    glAttachShader(deadline_program,dlinesegment_handle);
    glAttachShader(deadline_program,dvoronoi_handle);
    glAttachShader(deadline_program,stroke_handle);
    glAttachShader(deadline_program,dbox_handle);
    glAttachShader(deadline_program,ddeadline_handle);
    glAttachShader(deadline_program,zextrude_handle);
    glAttachShader(deadline_program,normal_handle);
    glLinkProgram(deadline_program);
#ifdef DEBUG
    printf("---> deadline Program:\n");
    debugp(deadline_program);
    printf(">>>>\n");
#endif
    glUseProgram(deadline_program);
    deadline_iTime_location = glGetUniformLocation(deadline_program, "iTime");
    deadline_iResolution_location = glGetUniformLocation(deadline_program, "iResolution");
    deadline_iFader0_location = glGetUniformLocation(deadline_program, "iFader0");
    deadline_iFader1_location = glGetUniformLocation(deadline_program, "iFader1");
    deadline_iFader2_location = glGetUniformLocation(deadline_program, "iFader2");
    deadline_iFader3_location = glGetUniformLocation(deadline_program, "iFader3");
    deadline_iFader4_location = glGetUniformLocation(deadline_program, "iFader4");
    deadline_iFader5_location = glGetUniformLocation(deadline_program, "iFader5");
    deadline_iFader6_location = glGetUniformLocation(deadline_program, "iFader6");
    deadline_iFader7_location = glGetUniformLocation(deadline_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadhydrant()
{
    int hydrant_size = strlen(hydrant_source);
    hydrant_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(hydrant_handle, 1, (GLchar **)&hydrant_source, &hydrant_size);
    glCompileShader(hydrant_handle);
#ifdef DEBUG
    printf("---> hydrant Shader:\n");
    debug(hydrant_handle);
    printf(">>>>\n");
#endif
    hydrant_program = glCreateProgram();
    glAttachShader(hydrant_program,hydrant_handle);
    glAttachShader(hydrant_program,rand_handle);
    glAttachShader(hydrant_program,lfnoise_handle);
    glAttachShader(hydrant_program,mfnoise_handle);
    glAttachShader(hydrant_program,hash11_handle);
    glAttachShader(hydrant_program,hash12_handle);
    glAttachShader(hydrant_program,hash21_handle);
    glAttachShader(hydrant_program,hash22_handle);
    glAttachShader(hydrant_program,hash31_handle);
    glAttachShader(hydrant_program,dvoronoi_handle);
    glAttachShader(hydrant_program,stroke_handle);
    glAttachShader(hydrant_program,dbox_handle);
    glAttachShader(hydrant_program,drhomboid_handle);
    glAttachShader(hydrant_program,dlinesegment_handle);
    glAttachShader(hydrant_program,zextrude_handle);
    glAttachShader(hydrant_program,add_handle);
    glAttachShader(hydrant_program,normal_handle);
    glAttachShader(hydrant_program,dpolygon_handle);
    glAttachShader(hydrant_program,dspacepigs_handle);
    glAttachShader(hydrant_program,analytical_box_handle);
    glLinkProgram(hydrant_program);
#ifdef DEBUG
    printf("---> hydrant Program:\n");
    debugp(hydrant_program);
    printf(">>>>\n");
#endif
    glUseProgram(hydrant_program);
    hydrant_iTime_location = glGetUniformLocation(hydrant_program, "iTime");
    hydrant_iResolution_location = glGetUniformLocation(hydrant_program, "iResolution");
    hydrant_iFader0_location = glGetUniformLocation(hydrant_program, "iFader0");
    hydrant_iFader1_location = glGetUniformLocation(hydrant_program, "iFader1");
    hydrant_iFader2_location = glGetUniformLocation(hydrant_program, "iFader2");
    hydrant_iFader3_location = glGetUniformLocation(hydrant_program, "iFader3");
    hydrant_iFader4_location = glGetUniformLocation(hydrant_program, "iFader4");
    hydrant_iFader5_location = glGetUniformLocation(hydrant_program, "iFader5");
    hydrant_iFader6_location = glGetUniformLocation(hydrant_program, "iFader6");
    hydrant_iFader7_location = glGetUniformLocation(hydrant_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadwatercubes()
{
    int watercubes_size = strlen(watercubes_source);
    watercubes_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(watercubes_handle, 1, (GLchar **)&watercubes_source, &watercubes_size);
    glCompileShader(watercubes_handle);
#ifdef DEBUG
    printf("---> watercubes Shader:\n");
    debug(watercubes_handle);
    printf(">>>>\n");
#endif
    watercubes_program = glCreateProgram();
    glAttachShader(watercubes_program,watercubes_handle);
    glAttachShader(watercubes_program,hash22_handle);
    glAttachShader(watercubes_program,dvoronoi_handle);
    glAttachShader(watercubes_program,hash33_handle);
    glAttachShader(watercubes_program,dvoronoi3_handle);
    glAttachShader(watercubes_program,smoothmin_handle);
    glAttachShader(watercubes_program,dsmoothvoronoi3_handle);
    glAttachShader(watercubes_program,rot3_handle);
    glAttachShader(watercubes_program,add_handle);
    glAttachShader(watercubes_program,dbox3_handle);
    glAttachShader(watercubes_program,dstar_handle);
    glAttachShader(watercubes_program,smoothmax_handle);
    glAttachShader(watercubes_program,dstar3_handle);
    glAttachShader(watercubes_program,normal_handle);
    glAttachShader(watercubes_program,dbox_handle);
    glLinkProgram(watercubes_program);
#ifdef DEBUG
    printf("---> watercubes Program:\n");
    debugp(watercubes_program);
    printf(">>>>\n");
#endif
    glUseProgram(watercubes_program);
    watercubes_iTime_location = glGetUniformLocation(watercubes_program, "iTime");
    watercubes_iResolution_location = glGetUniformLocation(watercubes_program, "iResolution");
    watercubes_iFader0_location = glGetUniformLocation(watercubes_program, "iFader0");
    watercubes_iFader1_location = glGetUniformLocation(watercubes_program, "iFader1");
    watercubes_iFader2_location = glGetUniformLocation(watercubes_program, "iFader2");
    watercubes_iFader3_location = glGetUniformLocation(watercubes_program, "iFader3");
    watercubes_iFader4_location = glGetUniformLocation(watercubes_program, "iFader4");
    watercubes_iFader5_location = glGetUniformLocation(watercubes_program, "iFader5");
    watercubes_iFader6_location = glGetUniformLocation(watercubes_program, "iFader6");
    watercubes_iFader7_location = glGetUniformLocation(watercubes_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadglitchcity()
{
    int glitchcity_size = strlen(glitchcity_source);
    glitchcity_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(glitchcity_handle, 1, (GLchar **)&glitchcity_source, &glitchcity_size);
    glCompileShader(glitchcity_handle);
#ifdef DEBUG
    printf("---> glitchcity Shader:\n");
    debug(glitchcity_handle);
    printf(">>>>\n");
#endif
    glitchcity_program = glCreateProgram();
    glAttachShader(glitchcity_program,glitchcity_handle);
    glAttachShader(glitchcity_program,hash22_handle);
    glAttachShader(glitchcity_program,hash12_handle);
    glAttachShader(glitchcity_program,dvoronoi_handle);
    glAttachShader(glitchcity_program,add_handle);
    glAttachShader(glitchcity_program,dbox3_handle);
    glAttachShader(glitchcity_program,normal_handle);
    glLinkProgram(glitchcity_program);
#ifdef DEBUG
    printf("---> glitchcity Program:\n");
    debugp(glitchcity_program);
    printf(">>>>\n");
#endif
    glUseProgram(glitchcity_program);
    glitchcity_iTime_location = glGetUniformLocation(glitchcity_program, "iTime");
    glitchcity_iResolution_location = glGetUniformLocation(glitchcity_program, "iResolution");
    glitchcity_iFader0_location = glGetUniformLocation(glitchcity_program, "iFader0");
    glitchcity_iFader1_location = glGetUniformLocation(glitchcity_program, "iFader1");
    glitchcity_iFader2_location = glGetUniformLocation(glitchcity_program, "iFader2");
    glitchcity_iFader3_location = glGetUniformLocation(glitchcity_program, "iFader3");
    glitchcity_iFader4_location = glGetUniformLocation(glitchcity_program, "iFader4");
    glitchcity_iFader5_location = glGetUniformLocation(glitchcity_program, "iFader5");
    glitchcity_iFader6_location = glGetUniformLocation(glitchcity_program, "iFader6");
    glitchcity_iFader7_location = glGetUniformLocation(glitchcity_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadgreetings()
{
    int greetings_size = strlen(greetings_source);
    greetings_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(greetings_handle, 1, (GLchar **)&greetings_source, &greetings_size);
    glCompileShader(greetings_handle);
#ifdef DEBUG
    printf("---> greetings Shader:\n");
    debug(greetings_handle);
    printf(">>>>\n");
#endif
    greetings_program = glCreateProgram();
    glAttachShader(greetings_program,greetings_handle);
    glAttachShader(greetings_program,rand_handle);
    glAttachShader(greetings_program,lfnoise_handle);
    glAttachShader(greetings_program,dhexagonpattern_handle);
    glAttachShader(greetings_program,dbox_handle);
    glAttachShader(greetings_program,dlinesegment_handle);
    glAttachShader(greetings_program,stroke_handle);
    glAttachShader(greetings_program,addwindow_handle);
    glAttachShader(greetings_program,dpolygon_handle);
    glAttachShader(greetings_program,dmercury_handle);
    glAttachShader(greetings_program,dcircle_handle);
    glAttachShader(greetings_program,dtriangle_handle);
    glAttachShader(greetings_program,rot_handle);
    glAttachShader(greetings_program,dschnappsgirls_handle);
    glAttachShader(greetings_program,dhaujobb_handle);
    glAttachShader(greetings_program,dkewlers_handle);
    glAttachShader(greetings_program,dfarbrausch_handle);
    glAttachShader(greetings_program,d5711_handle);
    glLinkProgram(greetings_program);
#ifdef DEBUG
    printf("---> greetings Program:\n");
    debugp(greetings_program);
    printf(">>>>\n");
#endif
    glUseProgram(greetings_program);
    greetings_iTime_location = glGetUniformLocation(greetings_program, "iTime");
    greetings_iResolution_location = glGetUniformLocation(greetings_program, "iResolution");
    greetings_iFader0_location = glGetUniformLocation(greetings_program, "iFader0");
    greetings_iFader1_location = glGetUniformLocation(greetings_program, "iFader1");
    greetings_iFader2_location = glGetUniformLocation(greetings_program, "iFader2");
    greetings_iFader3_location = glGetUniformLocation(greetings_program, "iFader3");
    greetings_iFader4_location = glGetUniformLocation(greetings_program, "iFader4");
    greetings_iFader5_location = glGetUniformLocation(greetings_program, "iFader5");
    greetings_iFader6_location = glGetUniformLocation(greetings_program, "iFader6");
    greetings_iFader7_location = glGetUniformLocation(greetings_program, "iFader7");
    progress += .2/(float)nprograms;
}

void Loadfractal()
{
    int fractal_size = strlen(fractal_source);
    fractal_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fractal_handle, 1, (GLchar **)&fractal_source, &fractal_size);
    glCompileShader(fractal_handle);
#ifdef DEBUG
    printf("---> fractal Shader:\n");
    debug(fractal_handle);
    printf(">>>>\n");
#endif
    fractal_program = glCreateProgram();
    glAttachShader(fractal_program,fractal_handle);
    glAttachShader(fractal_program,rand_handle);
    glAttachShader(fractal_program,lfnoise_handle);
    glAttachShader(fractal_program,hash22_handle);
    glAttachShader(fractal_program,dvoronoi_handle);
    glAttachShader(fractal_program,add_handle);
    glAttachShader(fractal_program,sub_handle);
    glAttachShader(fractal_program,zextrude_handle);
    glAttachShader(fractal_program,dbox3_handle);
    glAttachShader(fractal_program,rot3_handle);
    glAttachShader(fractal_program,dbox_handle);
    glAttachShader(fractal_program,dstar_handle);
    glAttachShader(fractal_program,doctahedron_handle);
    glAttachShader(fractal_program,normal_handle);
    glLinkProgram(fractal_program);
#ifdef DEBUG
    printf("---> fractal Program:\n");
    debugp(fractal_program);
    printf(">>>>\n");
#endif
    glUseProgram(fractal_program);
    fractal_iTime_location = glGetUniformLocation(fractal_program, "iTime");
    fractal_iResolution_location = glGetUniformLocation(fractal_program, "iResolution");
    fractal_iFader0_location = glGetUniformLocation(fractal_program, "iFader0");
    fractal_iFader1_location = glGetUniformLocation(fractal_program, "iFader1");
    fractal_iFader2_location = glGetUniformLocation(fractal_program, "iFader2");
    fractal_iFader3_location = glGetUniformLocation(fractal_program, "iFader3");
    fractal_iFader4_location = glGetUniformLocation(fractal_program, "iFader4");
    fractal_iFader5_location = glGetUniformLocation(fractal_program, "iFader5");
    fractal_iFader6_location = glGetUniformLocation(fractal_program, "iFader6");
    fractal_iFader7_location = glGetUniformLocation(fractal_program, "iFader7");
    progress += .2/(float)nprograms;
}

void LoadPrograms()
{
    Loadocean();
    updateBar();
    Loadlogo210();
    updateBar();
    Loadgraffiti();
    updateBar();
    Loadstarsky();
    updateBar();
    Loadtext();
    updateBar();
    Loadpost();
    updateBar();
    Loaddeadline();
    updateBar();
    Loadhydrant();
    updateBar();
    Loadwatercubes();
    updateBar();
    Loadglitchcity();
    updateBar();
    Loadgreetings();
    updateBar();
    Loadfractal();
    updateBar();
}
#endif
