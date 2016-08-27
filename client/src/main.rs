#[macro_use]
extern crate glium;

// We want to create a window with an OpenGL context handled by glium, instead
// of calling `build()` we will call `build_glium()` which is defined  in the
// `glium::DisplayBuild` trait
use glium::DisplayBuild;

fn main() {
    let display = glium::glutin::WindowBuilder::new().build_glium().unwrap();
    // preven the window from immediately closing by polling forever until we
    // recieve a `Closed` event
    loop {
        for ev in display.poll_events() {
            match ev {
                glium::glutin::Event::Closed => return, // window closed by user
                _ => (),
            }
        }
    }
}
