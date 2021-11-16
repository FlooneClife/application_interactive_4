#version 430

layout(binding = 0) uniform sampler2D grassTexture;
layout(binding = 1) uniform sampler2D rockTexture;
layout(binding = 2) uniform sampler2D snowTexture;

uniform sampler2D texture;

in vec2 v_texcoord;
in vec4 v_position;
//! [0]
void main()
{
    // Set fragment color from texture
    //gl_FragColor = texture2D(rockTexture, v_texcoord);
    gl_FragColor = vec4(v_position.x, v_position.y, v_position.z, 1.0);


//    if(v_position.z < 0.60) {
//        gl_FragColor = texture2D(grassTexture, v_texcoord);
//        //QOpenGLTexture(QImage(":/grass.png"));
//    } else if(v_position.z < 0.80) {
//        gl_FragColor = texture2D(rockTexture, v_texcoord);
//        //QOpenGLTexture(QImage(":/rock.png"));
//    } else {
//        gl_FragColor = texture2D(snowTexture, v_texcoord);
//        //QOpenGLTexture(QImage(":/snowrocks.png"));
//    }

}
//! [0]

