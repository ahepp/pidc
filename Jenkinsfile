pipeline {
    agent {
        dockerfile {
            args '-v ${WORKSPACE}:/ws'
        }
    }
    stages {
        stage('Configure') {
            steps {
                sh 'rm -rf /ws/build'
            }
        }
        stage('Build') {
            steps {
                sh 'mkdir /ws/build && cd /ws/build && cmake ..'
                sh 'make -C /ws/build'
            }
        }
    }
}
