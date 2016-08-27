#[macro_use]
extern crate glium;

// We want to create a window with an OpenGL context handled by glium, instead
// of calling `build()` we will call `build_glium()` which is defined  in the
// `glium::DisplayBuild` trait
use glium::DisplayBuild;
// to fill a `Frame` with color we need to import `Surface` trait
use glium::Surface;


#[derive(Copy, Clone)]
struct ArbitraryNameVertex {
    position: [f32; 2],
}

implement_vertex!(ArbitraryNameVertex, position);

fn main() {
    let display = glium::glutin::WindowBuilder::new().build_glium().unwrap();
        
    let vertex1 = ArbitraryNameVertex { position: [-0.5, -0.5] };
    let vertex2 = ArbitraryNameVertex { position: [0.0, 0.5] };
    let vertex3 = ArbitraryNameVertex { position: [0.5, -0.25] };

    let shape = vec![ vertex1, vertex2, vertex3];
    let vertex_buffer = glium::VertexBuffer::new(&display, &shape).unwrap();

    let mut t: f32 = -0.5;

    let vertex_shader_src = r#"
        #version 130
        in vec2 position;
        uniform float t;
        void main() {
            vec2 pos =  position;
            pos.x += t;
            gl_Position = vec4(pos, 0.0, 1.0);
        }
    "#;
    
    let fragment_shader_src = r#"
        #version 130
        out vec4 color;
        void main() {
            color = vec4(1.0, 0.0, 0.0, 1.0);
        }
    "#;
    // prevent the window from immediately closing by polling forever until we
    // recieve a `Closed` event
    loop {
        t += 0.02;
        if t > 0.5 {
            t = -0.5;
        }
        // draw a test image
        let mut target = display.draw();
        target.clear_color(0.0, 0.0, 1.0, 1.0);

        let indicies = glium::index::NoIndices(glium::index::PrimitiveType::TrianglesList);
        
        let program = glium::Program::from_source(&display,
                                                  vertex_shader_src,
                                                  fragment_shader_src,
                                                  None).unwrap();

        target.draw(&vertex_buffer, &indicies, &program,
                    &uniform! { t: t },
                    &Default::default()).unwrap();
        target.finish().unwrap();


        for ev in display.poll_events() {
            match ev {
                glium::glutin::Event::Closed => return, // window closed by user
                _ => (),
            }
        }
    }
}
